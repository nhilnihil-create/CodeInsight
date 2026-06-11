#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
    int n,m;
    cin>>n>>m;

    vector<int> a(m),b(m);
    rep(i,m){
        cin>>a[i]>>b[i];
        a[i]--,b[i]--;
    }
    reverse(all(a));
    reverse(all(b));

    UnionFind uf(n);
    vector<ll> ans(m);
    rep(i,m){
        if(uf.issame(a[i],b[i])) ans[i]=0;
        else{
            ll x=uf.size(a[i]);
            ll y=uf.size(b[i]);
            ans[i]=x*y;
            uf.merge(a[i],b[i]); 
        }
    }
    vector<ll> res(m);
    reverse(all(ans));
    //rep(i,m) cout<<ans[i]<<endl;
    res[0]=ans[0];
    for(int i=1;i<m;i++){
        res[i]=res[i-1]+ans[i];
    }

    rep(i,m) cout<<res[i]<<endl;
}