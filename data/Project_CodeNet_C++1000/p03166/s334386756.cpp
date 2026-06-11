#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(100005);
int d[100005], u[100005];

void dfs(int v) {
    u[v] = 1;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if(!u[to])
            dfs(to);
        d[v] = max(d[v], d[to]+1);
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i = 1; i <= n; i++)
        if(!u[i])
            dfs(i);

    cout << *max_element(d, d+n+2);

    return 0;
}
