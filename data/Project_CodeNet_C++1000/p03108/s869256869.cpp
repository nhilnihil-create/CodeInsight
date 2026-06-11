#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

int main(){
    ll n,m;
    cin >> n >> m;
    ve<P> e(m);
    ve<ll> ans(m);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        e[i] = P(a,b);
    }
    reverse(e.begin(), e.end());
    ans[0] = (n-1) * n /2;
    UnionFind uf(n);
    rep(i,m-1){
        if(uf.same(e[i].first, e[i].second)) ans[i+1] = ans[i];
        else ans[i+1] = ans[i] - uf.size(e[i].first) * uf.size(e[i].second);
        uf.unite(e[i].first, e[i].second);
    }
    reverse(ans.begin(), ans.end());
    rep(i,m) cout << ans[i] << endl;
}
