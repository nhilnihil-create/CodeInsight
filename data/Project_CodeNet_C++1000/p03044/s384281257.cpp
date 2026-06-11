#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n;
vector<int> adj[100005];
vector<int> dist;
map<P, int> mp;

void dfs(int v, int d = 0, int p = -1) {
    dist[v] = d % 2;
    for (int u : adj[v]) {
        if (u == p)
            continue;
        dfs(u, d + mp[make_pair(v, u)], v);
    }
}

vector<int> calcDist (int v) {
    dist = vector<int>(n);
    dfs(v);
    return dist;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;    v--;    w %= 2;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[make_pair(u, v)] = w;
        mp[make_pair(v, u)] = w;
    }
    
    auto col = calcDist(0);
    for (int c : col)
        cout << c << endl;
    
    return 0;
}