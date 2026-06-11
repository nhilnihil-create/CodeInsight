#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct UnionFind{
    vector<int> par;
    vector<int> siz;

    UnionFind(int n): par(n), siz(n){
        for(int i=0; i<n; i++){
            par[i] = i;
            siz[i] = 1;
        }
    }

    int root(int x){
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    int size(int x){
        if(par[x] == x) return siz[x];
        else return siz[x] = size(par[x]);
    }

    void unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx != ry){
            par[ry] = rx;
            siz[rx] += siz[ry];
        }
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

};


signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i=0; i<m; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    int ans = 0;
    for(int i=0; i<m; i++){
        UnionFind uf(n);
        for(int j=0; j<m; j++){
            if(i == j) continue;
            uf.unite(a[j], b[j]);
        }
        ans += (uf.size(0) != n);
    }
    cout << ans << endl;

    return 0;
}