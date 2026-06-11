#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5 + 5;

int n, color[mxn];
bool vis[mxn];
vector<pair<int, int>> adj[mxn];

void dfs(int u, int c) {
    vis[u] = true;
    color[u] = c;
    for (auto v : adj[u]) {
        if (vis[v.first] == false) {
            dfs(v.first, c ^ (v.second % 2));
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << color[i] << endl;
    }
}

