#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, black = 0, white = 0, color[100001];
bool visited[100001];
vector <int> adj[100001];
bool haichieu = 1;

void dfs(int v, int c) {
    for(auto u : adj[v]) {
        if(color[u] != -1) {
            if(color[u] != c) {
                haichieu = 0;
            }
        } 
        color[u] = c;
    }
    for(auto u : adj[v]) {
        if(!visited[u]) {
            visited[u] = 1;
            dfs(u, 1 - c);
        }
    }
}

signed main() {
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(color, -1, sizeof color);
    color[1] = 0;
    visited[1] = 1;
    dfs(1, 1);
    if(!haichieu) {
        return cout << (n * (n - 1)) / 2 - m << '\n', 0;
    }
    for(int i = 1; i <= n; i++) {
        if(color[i] == 1) {
            black++;
        } else if(color[i] == 0) {
            white++;
        }
    }
    cout << black * white - m << '\n';
}