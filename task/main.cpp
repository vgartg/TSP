#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int tsp(vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited, int current, int n, int cost) {
    if (visited[current] && count(visited.begin(), visited.end(), true) == n) {
        return cost + graph[current][0];
    }

    int min_cost = INF;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            path.push_back(i);
            int new_cost = tsp(graph, path, visited, i, n, cost + graph[current][i]);
            min_cost = min(min_cost, new_cost);
            path.pop_back();
            visited[i] = false;
        }
    }

    return min_cost;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = graph.size();
    vector<int> path = { 0 };
    vector<bool> visited(n, false);
    visited[0] = true;

    int min_cost = tsp(graph, path, visited, 0, n, 0);

    cout << "Minimum cost: " << min_cost << endl;
}