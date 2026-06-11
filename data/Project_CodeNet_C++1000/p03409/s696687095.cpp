#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++) 
using namespace std;

struct Match {
    int n;
    vector<vector<int>> G;
    vector<bool> used;
    vector<int> match;

    Match(int n_) : n(n_) { G.resize(n); }
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bool dfs(int v) {
        used[v] = true;
        for(auto nv : G[v]) {
            int vv = match[nv];
            if(vv < 0 || (!used[vv] && dfs(vv))) {
                match[v] = nv;
                match[nv] = v;
                return true;
            }
        }
        return false;
    }
    int solve() {
        int res = 0;
        match.assign(n,-1);
        for (int i = 0; i < n; i++) {
            if(match[i] >= 0) continue;
            used.assign(n,false);
            if(dfs(i)) res++;
        }
        return res;
    }
};

int main(){
    int n; cin >> n;
    int a[n], b[n], c[n], d[n];
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n) cin >> c[i] >> d[i];
    Match data(2*n);
    rep(i,n) rep(j,n) if(a[i] < c[j] && b[i] < d[j]) data.add_edge(i,j+n);
    cout << data.solve() << endl;
}