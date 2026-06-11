#define MOD_TYPE 2

#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
/*
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using multiInt = boost::multiprecision::cpp_int;
using lld = boost::multiprecision::cpp_dec_float_100;
*/
/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
*/
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
constexpr int INF = (int)1e9;
constexpr ll LINF = (ll)4e18;
constexpr ld PI = acos(-1.0);
constexpr ld EPS = 1e-11;
constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define REPI(i, m, n) for (int i = m; i < (int)(n); ++i)
#define repi(i, n) REPI(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

inline void init_main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);
}
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
inline ll CEIL(ll a, ll b)
{
  return (a + b - 1) / b;
}
#pragma endregion

struct UnionFind
{
  vector<int> par;
  vector<vector<int>> v;

  UnionFind() {}
  UnionFind(int n) : par(n), v(n) { init(n); }

  void init(int n)
  {
    par.resize(n);
    v.resize(n);
    iota(all(par), 0);
    for (int i = 0; i < n; i++)
      v[i].emplace_back(i);
  }

  int root(int x)
  {
    if (x == par[x])
      return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return;
    if (v[x].size() < v[y].size())
      swap(x, y);
    par[y] = x;
    while (!v[y].empty())
    {
      v[x].emplace_back(v[y].back());
      v[y].pop_back();
    }
  }

  bool same(int x, int y) { return root(x) == root(y); }

  int size(int x) { return v[root(x)].size(); }
};

struct BIT
{
  int n;
  vector<ll> dat;
  BIT(int n_) : n(n_), dat(n_, 0) {}

  // 0-indexed
  void add(int i, ll x)
  {
    i++;
    while (i <= n)
    {
      dat[i - 1] += x;
      i += i & -i;
    }
  }

  // [0,i)
  ll sum(int i)
  {
    ll res = 0;
    while (i > 0)
    {
      res += dat[i - 1];
      i -= i & -i;
    }
    return res;
  }

  // [l,r)
  ll sum(int l, int r)
  {
    if (l == 0)
      return sum(r);
    else
      return sum(r) - sum(l - 1);
  }
};

ll calc_inversion(vector<ll> &v)
{
  constexpr ll add = 100005;
  BIT bt(200010);
  ll res = 0;
  for (auto t : v)
  {
    res += bt.sum(0, t + 1 + add);
    bt.add(t + add, 1);
  }
  return res;
}

int main()
{
  init_main();

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll len = n * (n + 1) / 2;

  auto simulate = [&](ll x) {
    vector<ll> v(n + 1);
    v[0] = 0;
    rep(i, n)
    {
      if (a[i] < x)
        v[i + 1] = -1;
      else
        v[i + 1] = 1;
    }
    rep(i, n) v[i + 1] += v[i];
    return calc_inversion(v) >= (len + 1) / 2;
  };

  auto binary_search = [&]() {
    ll lo = 0, hi = INF + 1;
    while (hi - lo > 1)
    {
      ll mi = (lo + hi) / 2;
      if (simulate(mi))
        lo = mi;
      else
        hi = mi;
    }
    return lo;
  };

  cout << binary_search() << endl;
  return 0;
}
