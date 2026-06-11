#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

struct UnionFind {
  vector<int> d;
  UnionFind(int n) : d(n, -1) {}
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x, y);
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
  vector<P> p(m);
  rep(i, m) {
    cin >> p[i].first >> p[i].second;
    p[i].first--;
    p[i].second--;
  }
  reverse(all(p));
  UnionFind uf(n);
  vl ans(m + 1, n * (n - 1) / 2);
  rep(i, m) {
    ll a = p[i].first;
    ll b = p[i].second;
    ll sa = uf.size(a);
    ll sb = uf.size(b);
    ans[m - i - 1] = ans[m - i];
    ans[m - i - 1] += sa * (sa - 1) / 2;
    if(uf.root(a) != uf.root(b)) ans[m - i - 1] += sb * (sb - 1) / 2;
    uf.unite(a, b);
    ll s = uf.size(a);
    ans[m - i - 1] -= s * (s - 1) / 2;
  }
  rep(i, m) cout << ans[i + 1] << '\n';
}