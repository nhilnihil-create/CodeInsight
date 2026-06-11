#include <iostream>
#include <vector>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
using namespace std;

class UnionFind {
public:
  vector<ll> par;
  vector<ll> siz;
  
  UnionFind(ll sz_) : par(sz_), siz(sz_, 1) {
    for(int i = 0; i < sz_; i++) par[i] = i;
  }
  
  void init(ll sz_){
    par.resize(sz_);
    siz.assign(sz_, 1);
    for (ll i = 0; i < sz_; ++i) par[i] = i;
  }
  
  ll root(ll x){
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  
  bool unite(ll x, ll y){
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }
  
  bool same(ll x, ll y){
    return root(x) == root(y);
  }
    
  ll size(ll x){
    return siz[root(x)];
  }
};

int main(){
  ll n, m;
  cin >> n >> m;
  vector<ll> a(m), b(m);
  rep(i, m){
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  vector<ll> ans(m+1);
  ans[m] = n*(n-1)/2;
  UnionFind tree(n);
  repr(i, m){
    ans[i] = ans[i+1];
    if (!tree.same(a[i], b[i])) ans[i] -= tree.size(a[i]) * tree.size(b[i]);
    tree.unite(a[i], b[i]);
  }
  rep(i, m) cout << ans[i+1] << endl;
  
  return 0;
}