#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;

vector < vector < pair < int, int > > > g(maxn);
vector < int > d(maxn, 0);

void dfs (int u, int p) {
    for (auto edge: g[u]) {
        int v = edge.first, w = edge.second;
        if (v != p) {
            d[v] = ((d[u] + w) & 1);
            dfs(v, u);
        }
    }
}

signed main () {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, (w & 1)));
        g[v].push_back(make_pair(u, (w & 1)));
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i)
        cout << d[i] << '\n';
}
