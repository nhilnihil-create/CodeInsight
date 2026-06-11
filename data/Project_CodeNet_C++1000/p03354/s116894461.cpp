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

  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  map<int, int> mp1, mp2;
  rep(i, 0, n) {
    int x;
    cin >> x;
    p[i] = x;
    mp1[x] = i + 1;
    mp2[i + 1] = x;
  }
  UnionFind uf(n);
  rep(i, 0, m) {
    int x, y;
    cin >> x >> y;
    uf.merge(x, y);
  }

  rep(i, 0, n) {
    if (i + 1 != mp2[i + 1] && uf.is_same(i + 1, mp2[i + 1])) {
      int old = mp1[i+1];
      swap(mp1[i + 1], mp1[mp2[i + 1]]);
      swap(mp2[old], mp2[mp1[i + 1]]);
    }
  }

  int ans = 0;
  for (auto m : mp2)
    if (m.first == m.second)
      ans++;
  cout << ans << endl;
}
