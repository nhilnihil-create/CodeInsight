/**
 *    author:  FromDihPout
 *    created: 2020-08-16
**/

#include <bits/stdc++.h>
using namespace std;


void dfs(int u, set<int> &comp, vector<vector<int>> &adj) {
    comp.insert(u);
    for (int v : adj[u]) {
        if (comp.count(v)) continue;
        dfs(v, comp, adj);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<bool> seen(n+1);
    set<int> comp;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (seen[i]) continue;
        comp.clear();
        dfs(i, comp, adj);
        for (int x : comp) {
            if (comp.count(p[x])) ans++;
            seen[x] = true;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (!seen[i] && p[i] == i) ans++;
    }
    cout << ans << '\n';
    return 0;
}