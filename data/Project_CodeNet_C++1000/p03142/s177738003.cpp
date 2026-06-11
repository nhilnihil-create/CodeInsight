#include <bits/stdc++.h>


using namespace std;

const int MAXN = 100 * 1000 + 23;





int n, m, d[MAXN], par[MAXN];
vector<int> g[MAXN];

void dfs(int v) {
    for (auto u : g[v])
        if (--d[u] == 0)
            par[u] = v;
    for (auto u : g[v])
        if (d[u] == 0)
            dfs(u);
}



int main() {
    cin >> n >> m;
    for (int i = 1; i < n + m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        d[v]++;
    }
    int st;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            st = i;
    dfs(st);
    for (int i = 1; i <= n; i++)
        cout << par[i] << '\n';
    return 0;
}