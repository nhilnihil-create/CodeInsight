#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

struct UnionFind {
  vector<int> par; // 親
  vector<int> siz; // サイズ
 
  UnionFind(int n) {
    par = vector<int>(n);
    siz = vector<int>(n, 1);
    rep(i, n) {
      par[i] = i;
    }
  }
 
  int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
 
  bool same(int x, int y) {
    return root(x) == root(y);
  }
 
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
  }
 
  int size(int x) {
    return siz[root(x)];
  }
};

int main() {
  ll n,m;
  cin>>n>>m;
  vector<pair<int, int>> v(m);
  rep(i, m) {
    int a,b;
    cin>>a>>b;
    a--; b--;
    v[i] = {a, b};
  }
  UnionFind uf(n);
  vector<ll> ans;
  // 橋が存在しないときの不便さ
  ll cur = n * (n - 1) / 2;
  // 逆順に橋を架けていく
  for(int i = m - 1; i >= 0; i--) {
    ans.push_back(cur);
    if (uf.same(v[i].first, v[i].second)) {
      // 既に繋がっているなら不便さは変わらない
    } else {
      cur -= uf.size(v[i].first) * uf.size(v[i].second);
      uf.unite(v[i].first, v[i].second);
    }
  }
  reverse(ans.begin(), ans.end());
  for(ll x : ans) {
    cout << x << endl;
  }
}
