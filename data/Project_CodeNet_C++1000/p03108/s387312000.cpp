#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

struct UnionFind {
  vector<int> par;
  vector<int> sizes;

  UnionFind(int N) : par(N), sizes(N, 1) {
    for (int i = 0; i < N; i++) par.at(i) = i;
  }

  int find(int x) {
    if (par.at(x) == x) return x;
    return par.at(x) = find(par.at(x));
  }

  void unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (sizes.at(rx) < sizes.at(ry)) swap(rx, ry);
    par.at(ry) = rx;
    sizes.at(rx) += sizes.at(ry);
  }

  bool same(int x, int y) { return find(x) == find(y); }

  int size(int x) { return sizes.at(find(x)); }

  int num_of_connected_components() {
    int ret = 0;
    for (int i = 0; i < par.size(); i++) {
      if (find(i) == i) ret++;
    }
    return ret;
  }
};

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> ans(m);
  vector<ll> a(m), b(m);
  REP(i, m) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  ans[m - 1] = n * (n - 1) / 2;
  UnionFind uf(n);
  IFOR(i, 1, m) {
    ans[i - 1] =
        ans[i] - (uf.same(a[i], b[i]) ? 0 : uf.size(a[i]) * uf.size(b[i]));
    uf.unite(a[i], b[i]);
  }

  REP(i, m) { cout << ans[i] << endl; }
}