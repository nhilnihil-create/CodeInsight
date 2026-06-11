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

  UnionFind uf(n);
  rep(i, 0, m) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    uf.merge(x, y);
  }

  set<int> groups;
  rep(i, 0, n) { groups.insert(uf.root(i)); }

  cout << (int)groups.size() << endl;
}
