#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool Dfs(const int cur, auto &visited, const auto &adj) {
    visited[cur] = 1;
    for (auto v : adj[cur]) {
        if (visited[v] == 1) return true;
        else if (!visited[v] && Dfs(v, visited, adj)) return true;
    }
    visited[cur] = 2;
    return false;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<vector<int>> adj(2 * n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v; --u; --v;
        if (s[u] == s[v]) {
            adj[u].push_back(v + n);
            adj[v].push_back(u + n);
        }
        else {
            adj[u + n].push_back(v);
            adj[v + n].push_back(u);
        }
    }

    vector<char> visited(2 * n, 0);
    bool is_cycle = false;
    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            if (Dfs(v, visited, adj)) {
                is_cycle = true;
                break;
            }
        }
    }

    if (is_cycle) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
