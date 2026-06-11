#include <bits/stdc++.h>
using namespace std;
#define int long long

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
        int rx = root(x);
        int ry = root(y);
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

    UnionFind uf(n);

    vector<int> ans(m);
    for(int i=m-1; i>=0; i--){
        int sa = uf.size(a[i]);
        int sb = uf.size(b[i]);
        if(uf.same(a[i], b[i])){
            ans[i] = 0;
        }
        else{
            ans[i] = sa*sb;
        }
        uf.unite(a[i], b[i]);
    }

    for(int i=0; i<m-1; i++){
        ans[i+1] += ans[i];
    }

    for(int i=0; i<m; i++){
        cout << ans[i] << endl;
    }

    return 0;
}