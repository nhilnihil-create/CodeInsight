/**
 *    author:  FromDihPout
 *    created: 2020-08-09
**/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

vector<vector<int>> adj;
vector<pair<int,int>> edges;
vector<bool> seen;

void del(int u, int par, int e) {
    seen[u] = true;
    for (int v : adj[u]) {
        if (v == par) continue;
        if (u == edges[e].first && v == edges[e].second) continue;
        if (v == edges[e].first && u == edges[e].second) continue;
        if (seen[v]) continue;
        del(v, u, e);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        seen.clear();
        seen.resize(n);
        fill(all(seen), false);
        del(0, -1, i);
        
        for (bool visited : seen) {
            if (!visited) {
                ans++;
                break;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}