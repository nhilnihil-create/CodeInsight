#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
class UnionFind {
public:
  vector <int> par; // 各元の親を表す配列
  vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)
 
  // Constructor
  UnionFind(int sz_): par(sz_), siz(sz_, 1) {
    for (int i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
  }
  void init(int sz_) {
    par.resize(sz_);
    siz.assign(sz_, 1LL);
    for (int i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
  }
 
  // Member Function
  // Find
  int root(int x) { // 根の検索
    while (par[x] != x) {
      x = par[x] = par[par[x]]; // x の親の親を x の親とする
    }
    return x;
  }
 
  // Union(Unite, Merge)
  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    // merge technique（データ構造をマージするテク．小を大にくっつける）
    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }
 
  bool issame(int x, int y) { // 連結判定
    return root(x) == root(y);
  }
 
  ll size(int x) { // 素集合のサイズ
    return siz[root(x)];
  }
};
 
int main() {
  int n,m;
  cin >> n >> m;
  UnionFind uf(n);
  ll ans = ((ll)n*((ll)n-1LL))/2LL;
  vector<P> bs(m);
  rep(i,0,m) cin >> bs[i].fi >> bs[i].se;
  vector<ll> a(m);
  rrep(i,m,0) {
    a[i] = ans;
    int a = bs[i].fi, b = bs[i].se;
    a--; b--;
    if (!uf.issame(a, b)) {
      ll sa = uf.size(a), sb = uf.size(b);
      ans -= sa * sb;
      uf.merge(a, b);
    }
  }
  rep(i,0,m) cout << a[i] << "\n";
  return 0;
}