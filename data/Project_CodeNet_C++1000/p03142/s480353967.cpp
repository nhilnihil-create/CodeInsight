#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T, class U> inline bool chmax(T& a,U b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> inline bool chmin(T& a,U b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n, m, s;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> indeg(n, 0);
    vector<int> par(n, -1);
    queue<pair<int, int>> que;
    for (int i = 0; i < n+m-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        indeg[b]++;
        g[a].emplace_back(b);
    }
    
    for (int i = 0; i < n; i++) if (!indeg[i]) s = i;
    
    que.emplace(s, s);
    while (!que.empty()) {
        int v, p; tie(v, p) = que.front(); que.pop();
        for (auto u : g[v]) {
            if (indeg[u] == 1) { par[u] = v; que.emplace(u, v); }
            else { indeg[u]--; }
        }
    }
    
    for (auto ans : par) cout << ++ans << endl;
    
    return 0;
}