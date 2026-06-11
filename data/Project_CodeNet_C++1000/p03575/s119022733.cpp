#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
struct UnionFind{
    vector<long long> size, par;
    UnionFind(long long n) {
        size.resize(n, 0);
        par.resize(n, 0);
        for (long long i = 0; i < n;i++){
            maketree(i);
        }
    }
    void maketree(long long x){
        par[x] = x;
        size[x] = 1;
    }
    long long findroot(long long x){
        if (x != par[x]) par[x] = findroot(par[x]);
        return par[x];
    }
    bool issame(long long x,long long y){
        return findroot(x) == findroot(y);
    }
    bool unite(long long x,long long y){
        x = findroot(x);
        y = findroot(y);
        if (x == y) return false;  //already united
        if(size[x]>size[y]){
            par[y] = x;
            size[x] += size[y];
        }
        else{
            par[x] = y;
            size[y] += size[x];
        }
        return true;
    }
    long long treesize(long long x){
        return size[findroot(x)];
    }
};

int main(){
ll n,m;
ll ans = 0;
cin >> n >> m;
ll a[m],b[m];
for (ll i = 0; i < m;i++){
    cin >> a[i]>>b[i];
    a[i]--;
    b[i]--;
}
    for (ll i = 0; i < m; i++) {
        UnionFind uf(n);
        for (ll j = 0; j < m; j++) {
            if (i == j)
                continue;
            else
                uf.unite(a[j], b[j]);
        }
        if (uf.treesize(0) != n) ans++;
    }
cout << ans << endl;
}