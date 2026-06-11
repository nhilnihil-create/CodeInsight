#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

struct UnionFind {
  // 子は親のID,親は-サイズ
  vector<int> d;
  UnionFind(int n) : d(n, -1) {}
  int root(int x) {
    if (d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -d[root(x)]; }
};

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(m), b(m), ans;
  rep(i, m) cin >> a[i] >> b[i], a[i]--, b[i]--;

  ans.push_back(n * (n - 1) / 2);

  UnionFind uf(n);
  for (int i = m - 1; i > 0; --i) {
    if (uf.same(a[i], b[i]))
      ans.push_back(ans.back());
    else
      ans.push_back(ans.back() - (ll)uf.size(a[i]) * (ll)uf.size(b[i]));
    uf.unite(a[i], b[i]);
  }
  reverse(ans.begin(), ans.end());

  rep(i, m) cout << ans[i] << endl;
  return 0;
}
