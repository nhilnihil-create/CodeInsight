/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.11 18:48:48
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;


bool nibu_judge(const std::vector< std::vector< int > > &G, int &one, int &zero) {
    int n = G.size();
    std::vector< int > mark(n,-1); 
    struct vertex { int v; int p; int m; };
    for (int i = 0; i < n; i++) {
        if (mark[i] != -1) continue;
        std::stack<vertex> sta;
        sta.push({i,-1,0}); 
        while (!sta.empty()) {
            vertex q = sta.top(); sta.pop();
            int v = q.v, p = q.p, m = q.m;
            if (mark[v] != -1) {
                if (mark[v] != m) return false;
                continue;
            }
            mark[v] = m;
            for (int u : G[v]) {
                if (u == p) continue;
                sta.push({u,v,1 - m});
            }
        }
    }
    one = 0;
    zero = 0;
    for (int i = 0; i < n; i++) {
        if (mark[i] == 0) zero++;
        else one++;
    }
    return true;
}
int main() {
    int n,m;cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int one,zero;
    if (nibu_judge(g,one,zero)) {
        cout << (ll)one * zero - m << endl;
    }
    else {
        cout << (ll)n * (n - 1) / 2 - m << endl;
    }
    return 0;
}
