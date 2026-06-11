#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

struct UnionFind {
  vector<int> par;
  vector<int> rank;
  vector<ll> Size;
  UnionFind(int n = 1) { init(n); }

  void init(int n = 1) {
    par.resize(n + 1);
    rank.resize(n + 1);
    Size.resize(n + 1);
    for (int i = 0; i <= n; ++i)
      par[i] = i, rank[i] = 0, Size[i] = 1;
  }

  int root(int x) {
    if (par[x] == x) {
      return x;
    } else {
      int r = root(par[x]);
      return par[x] = r;
    }
  }

  bool is_same(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (rank[x] < rank[y])
      swap(x, y);
    if (rank[x] == rank[y])
      ++rank[x];
    par[y] = x;
    Size[x] += Size[y];
    return true;
  }

  ll size(int x) { return Size[root(x)]; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;
  vector<P> v(m);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v[i] = make_pair(a, b);
  }

  vector<ll> ans(m);
  ans[m - 1] = (n * (n - 1)) / 2;

  UnionFind uf(n);
  repr(i, 0, m - 1) {
    if (uf.is_same(v[i + 1].first, v[i + 1].second))
      ans[i] = ans[i + 1];
    else
      ans[i] = ans[i + 1] -
               (ll)(uf.size(v[i + 1].first)) * (ll)(uf.size(v[i + 1].second));
    uf.merge(v[i + 1].first, v[i + 1].second);
  }

  rep(i, 0, m) cout << ans[i] << endl;
}
