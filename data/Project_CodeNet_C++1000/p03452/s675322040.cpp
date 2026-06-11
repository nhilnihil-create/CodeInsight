#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;
bool mark[N];
bool ans = true;
vector<pii> adj[N];
int d[N];

void dfs(int root) {
    mark[root] = true;
    for (int i = 0; i < adj[root].size(); i++) {
        int u = adj[root][i].first, w = adj[root][i].second;
        if (!mark[u]) {
            d[u] = d[root] + w;
            dfs(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m, u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[--u].push_back({--v, w});
        adj[v].push_back({u, -w});
    }
    for (int i = 0; i < n; i++)
        if (!mark[i])
            dfs(i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++)
            if (d[adj[i][j].first] != d[i] + adj[i][j].second)
                ans = false;
    }
    cout << (ans? "Yes": "No") << "\n";
    return 0;
}