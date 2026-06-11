#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

vector<int> path; 

void dfs(int v, vector<int> adj[], vector<bool> &visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) 
            dfs(u, adj, visited);
    }
    path.eb(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<bool> visited(n + 1);
    for (int i = 1; i <= n + m - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].eb(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) 
            dfs(i, adj, visited);
    }
    reverse(path.begin(), path.end());
    vector<int> p(n + 1);
    for (int i = 0; i < n; ++i) {
        int v = path[i];
        for (int u : adj[v]) {
            p[u] = v;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << "\n";
    }
    return 0;
}