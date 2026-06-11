#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

class UnionFind {
  vector<int> par, sz;
public:
  UnionFind(int n) : par(n), sz(n, 1) {
    for (int i = 0; i < n; i++)
      par[i] = i;
  }
  int root(int x) {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int size(int x) {
    return sz[root(x)];
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (sz[x] >= sz[y]) {
      sz[x] += sz[y];
      par[y] = x;
    } else {
      sz[y] += sz[x];
      par[x] = y;
    }
    return true;
  }
};

signed main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  UnionFind uf(n);
  vector<ll> res(m);
  res[m-1] = (ll)n*(n-1)/2;
  for(int i = m-1; i > 0; i--) {
    ll sa = uf.size(a[i]), sb = uf.size(b[i]);
    if(uf.unite(a[i], b[i]))
      res[i-1] = res[i]-sa*sb;
    else
      res[i-1] = res[i];
  }
  rep(i, m)
    cout << res[i] << endl;
  return 0;
}