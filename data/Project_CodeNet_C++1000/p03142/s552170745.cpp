#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], par[N], h[N];
bool mark[N];
vector<int> adj[N];

void dfs(int root) {
    mark[root] = true;
    par[root] = -1;
    for (auto v: adj[root]) {
        if (!mark[v])
            dfs(v);
        if (h[v] + 1 > h[root]) {
            h[root] = h[v] + 1;
            par[root] = v;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < n + m - 1; i++) {
        cin >> u >> v;
        adj[--v].push_back(--u);
    }
    for (int i = 0; i < n; i++)
        if (!mark[i])
            dfs(i);
    for (int i = 0; i < n; i++)
        cout << par[i] + 1 << "\n";
    return 0;
}