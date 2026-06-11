#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct UnionFind {
public:
  vector<ll> par; 
  vector<ll> siz; 

    
  UnionFind(ll sz_): par(sz_), siz(sz_, 1) {
    for (ll i = 0; i < sz_; ++i) par[i] = i; 
  }
  void init(ll sz_) {
    par.resize(sz_);
    siz.resize(sz_, 1);
    for (ll i = 0; i < sz_; ++i) par[i] = i;
  }

  ll root(ll x) { 
    while (par[x] != x) {
      x = par[x] = par[par[x]];
    }
    return x;
  }

  bool merge(ll x, ll y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }

  bool issame(ll x, ll y) {
    return root(x) == root(y);
  }

  ll size(ll x) {
    return siz[root(x)];
  }
};

int main() {
  ll n, m;
  cin >> n >> m;
  UnionFind uf(2 * n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    uf.merge(a, b + n);
    uf.merge(a + n, b);
  }

  rep(i, n) {
    if (uf.issame(i, n + i)) {
      cout << n * (n - 1) / 2 - m << endl;
      return 0;
    }
  }
  ll cnt = 0;
  rep(i, n) {
    if (uf.issame(0, i)) cnt++;
  }
  cout << cnt * (n - cnt) - m << endl;




  
  return 0;
}
