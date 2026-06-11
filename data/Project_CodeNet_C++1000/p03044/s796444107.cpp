#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 1e5 + 5;
int N; vector<pii> g[MN];
int a[MN];

void dfs(int u, int p) {
    for (auto e : g[u]) {
        int v = e.first, w = e.second;
        if (v == p) continue;
        if (w & 1) a[v] = a[u] ^ 1;
        else a[v] = a[u];
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    a[1] = 0;
    dfs(1, -1);
    for (int i = 1; i <= N; i++) cout << a[i] << '\n';
    return 0;
}