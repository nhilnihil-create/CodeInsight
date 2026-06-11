#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

struct UnionFind {
  vector<int> par;
  vector<int> siz;

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
  int n,m;
  cin>>n>>m;
  vector<pair<int, int>> v;
  rep(i, m) {
    int a,b;
    cin>>a>>b;
    a--; b--;
    v.push_back({a,b});
  }
  // 1本以外の辺を架けてチェック
  int ans = 0;
  rep(i, m) {
    UnionFind uf(n);
    rep(j, m) {
      if (i != j) uf.unite(v[j].first, v[j].second);
    }
    set<int> s;
    rep(j, n) {
      s.insert(uf.root(j));
    }
    if (s.size() > 1) ans++;
  }
  cout << ans;
}
