#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, M;

struct Unionfind {
    vector<int> par, rank;
    
    Unionfind(int n) {
        par.resize(n);
        fill(par.begin(), par.end(), -1);
        rank.resize(n);
    }
    
    int root(int x) {
        int r = x;
        while (!(par[r]<0)) r = par[r];
        int t = x;
        
        while (t!=r) {
            int tmp = t;
            t = par[t];
            par[tmp] = r;
        }
        
        return r;
    }
    
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        
        if (rx==ry) return;
        
        if (rank[rx]<=rank[ry]) {
            par[ry] += par[rx];
            par[rx] = ry;
            
            if (rank[rx]==rank[ry]) rank[ry]++;
        }
        else {
            par[rx] += par[ry];
            par[ry] = rx;
        }
    }
    
    bool is_same(int x, int y) {
        return root(x)==root(y);
    }
    
    int count(int x) {
        return -par[root(x)];
    }
};

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    Unionfind uf(N);
    rep(i, M) {
        int X, Y, Z; cin >> X >> Y >> Z;
        uf.unite(X-1, Y-1);
    }
    set<int> s;
    rep(i, N) s.insert(uf.root(i));
    cout << s.size() << endl;
}