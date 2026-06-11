#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;


struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1){}

    int root(int x) {
        if(par[x]<0) return x;
        return par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        return root(x)==root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x==y) return false;
        if(x>y) swap(x, y);
        par[x]+=par[y];
        par[y] = x;
        return true;
    }

    int size(int x){
        return -par[root(x)];
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i,m) {
        cin >> a[i] >> b[i]; a[i]--, b[i]--;
    }

    UnionFind uf(n);
    vector<ll> ans;
    ll now = n*(n-1)/2;
    rep(i,m){
        ans.push_back(now);
        int aa = a[m-1-i], bb = b[m-1-i];
        if(uf.same(aa, bb)) continue;
        ll s = uf.size(aa), t = uf.size(bb);
        now -= s*t;
        uf.unite(aa, bb);
    }
    reverse(all(ans));
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}