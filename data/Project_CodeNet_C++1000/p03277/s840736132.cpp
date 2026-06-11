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

template <typename T>
class SegmentTree
{
private:
  using Fn = function<T(T, T)>;
  int N;
  vector<T> dat;
  T unit;
  Fn func;

public:
  SegmentTree() {}
  SegmentTree(int n_, Fn func_, T unit_) { init(n_, func_, unit_); }
  SegmentTree(vector<T> &v, Fn func_, T unit_) { init(v, func_, unit_); }

  void init(int n_, Fn func_, T unit_)
  {
    func = func_, unit = unit_;
    N = 1;
    while (N < n_)
      N *= 2;
    dat.assign(2 * N - 1, unit);
  }

  void init(vector<T> &v, Fn func_, T unit_)
  {
    func = func_, unit = unit_;
    N = 1;
    int sz = v.size();
    while (N < sz)
      N *= 2;
    dat.resize(2 * N - 1);
    for (int i = 0; i < N; ++i)
      dat[i + N - 1] = (i < sz ? v[i] : unit);
    for (int i = N - 2; i >= 0; --i)
      dat[i] = func(dat[i * 2 + 1], dat[i * 2 + 2]);
  }

  void update(int k, T a)
  {
    k += N - 1;
    dat[k] = a;
    while (k > 0)
    {
      k = (k - 1) / 2;
      dat[k] = func(dat[k * 2 + 1], dat[k * 2 + 2]); //
    }
  }

  T query(int a, int b, int k, int l, int r)
  {
    if (r <= a || b <= l)
      return unit;
    if (a <= l && r <= b)
      return dat[k];
    else
    {
      T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return func(vl, vr);
    }
  }
  T query(int a, int b) { return query(a, b, 0, 0, N); }
};

ll calc_inversion(vector<ll> &v)
{
  constexpr ll add = 100005;
  SegmentTree<ll> sg(200010, plus<ll>(), 0LL);
  ll res = 0;
  for (auto t : v)
  {
    res += sg.query(0, t + 1 + add);
    sg.update(t + add, sg.query(t + add, t + add + 1) + 1);
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
