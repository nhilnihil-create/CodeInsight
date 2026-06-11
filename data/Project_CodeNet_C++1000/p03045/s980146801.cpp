#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
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
  UnionFind uf(n);
  rep(i, m) {
    ll x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    uf.unite(x, y);
  }
  set<ll> st;
  rep(i, n) st.insert(uf.root(i));
  cout << st.size() << endl;
}