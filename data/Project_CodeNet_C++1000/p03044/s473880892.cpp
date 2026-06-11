#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void dfs(vector<vector<pair<int, ll>>> &g, vector<int> &color, int v, int cost) {
    if (color[v] != -1) return;

    if (cost % 2) color[v] = 0;
    else color[v] = 1;
    for (auto &&x : g[v]) {
        dfs(g, color, x.first, cost + x.second);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, ll>>> g(n);

    for (int i = 0; i < n - 1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> color(n, -1);
    dfs(g, color, 0, 0);

    for (int x : color) {
        cout << x << endl;
    }
    return 0;
}