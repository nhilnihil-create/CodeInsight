#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++) 
using namespace std;

struct Match {
    int n, m;
    vector<vector<int>> G;
    vector<bool> used;
    vector<int> from, to;

    Match(int n, int m): n(n), m(m) { G.resize(n); }
    void add_edge(int from_, int to_) { G[from_].push_back(to_); }

    bool dfs(int v) {
        if (used[v]) return false;
        used[v] = true;
        for (auto nv : G[v]) {
            if (to[nv] == -1 || dfs(to[nv])) {
                from[v] = nv;
                to[nv] = v;                
                return true;
            }
        }
        return false;
    }

    int solve() {
        int res = 0;
        used.assign(n,false);
        from.assign(n,-1);
        to.assign(m,-1);
        bool update = true;
        while (update) {
            update = false;
            for (int i = 0; i < n; i++) if (from[i] == -1 && dfs(i)) { update = true; res++; }
            if (update) used.assign(n,false);
        }
        return res;
    }
};

int main(){
    int n; cin >> n;
    int a[n], b[n], c[n], d[n];
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n) cin >> c[i] >> d[i];
    Match data(n,n);
    rep(i,n) rep(j,n) if(a[i] < c[j] && b[i] < d[j]) data.add_edge(i,j);
    cout << data.solve() << endl;
}