#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct UnionFind {
  vector<int> par;

  UnionFind(int N) : par(N) {
    rep(i, N) par[i] = i;
  }

  int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par[rx] = ry;
  }

  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  rep(i, n) cin >> p[i];

  UnionFind tree(n);

  rep(i, m) {
    int x, y;
    cin >> x >> y;
    tree.unite(x-1, y-1);
  }

  int c = 0;
  rep(i, n) {
    if (tree.same(i, p[i]-1)) c++;
  }

  cout << c << endl;

  return 0;
}
