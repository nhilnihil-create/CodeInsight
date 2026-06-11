#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int st[N], p[N], mark[N];
vector <int> g[N], vec;

void dfs(int v) {
    mark[v] = 1;
    for (int u : g[v]) if (!mark[u]) p[u] = v, dfs(u);
    vec.push_back(v);
}

bool cmp(int i, int j) {return st[i] < st[j];}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m; m += n - 1;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) if (!mark[i]) dfs(i);
    reverse(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) st[vec[i]] = i;
    for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end(), cmp);
    memset(p, 0, sizeof p), memset(mark, 0, sizeof mark), dfs(vec[0]);
    for (int i = 1; i <= n; i++) cout << p[i] << "\n";


    return 0;
}
