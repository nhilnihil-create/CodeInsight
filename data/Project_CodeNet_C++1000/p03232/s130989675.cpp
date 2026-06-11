#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define BITF(n, i) (((n) >> i) & 1)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPI(i, x) for (int i = 1; i <= x; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define REPZ(i, x) for (int i = 0; i <= x; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, n) for (auto &&i : n)
#define FORI(i, m, n) for (int i = m; i <= n; i++)
using namespace std;
#define PRINTARR(x, y)                                     \
  cerr << #x << "=\n";                                     \
  for (auto itr = x; itr != y; itr++) cerr << *itr << " "; \
  cerr << endl;
#define PRINTARR2(x, i0, i1)                                       \
  cerr << #x << "=\n";                                             \
  for (int ii0 = 0; ii0 < i0; ii0++) {                             \
    for (int ii1 = 0; ii1 < i1; ii1++) cerr << x[ii0][ii1] << " "; \
    cerr << endl;                                                  \
  }
#define DUMPOUT cerr
// vector
template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
  for (T &x : vec) is >> x;
  return is;
}
// pair
template <typename T, typename U> ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
// vector
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "{";
  REP(i, (int)vec.size())
  os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
  os << "}";
  return os;
}
// map
template <typename T, typename U> ostream &operator<<(ostream &os, map<T, U> &map_var) {
  os << "{";
  FORA(itr, map_var) {
    os << *itr;
    itr++;
    if (itr != map_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
// set
template <typename T> ostream &operator<<(ostream &os, set<T> &set_var) {
  os << "{";
  FORA(itr, set_var) {
    os << *itr;
    itr++;
    if (itr != set_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) {
  DUMPOUT << head;
  if (sizeof...(Tail) > 0) DUMPOUT << ", ";
  dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define DUMP(...)                                                             \
  DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                             \
          << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" << endl \
          << "    ",                                                          \
      dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define DUMP(...)
#endif
#define ALL(v) v.begin(), v.end()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define epb emplace_back
#define int long long
#define pint pair<int, int>
#define ld long double
using namespace std;
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> using vec = std::vector<T>;
template <class T> void print(const T &x) { cout << x << "\n"; }
const int MOD = 1000000007, INF0 = 1061109567, INF = INF0 * INF0;
const double EPS = 1e-10, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int FACTSIZE = 100100;
int fact[FACTSIZE];
int revfact[FACTSIZE];

int binpow(int a, int b, int mo) {
  int ans = 1;
  do {
    if (b & 1) ans = 1ll * ans * a % mo;
    a = 1ll * a * a % mo;
  } while (b >>= 1);
  return ans;
}

int ncr(int n, int r) {
  if (n < r) return 0;
  int rs = fact[n] * revfact[r];
  if (rs >= MOD) rs %= MOD;
  rs *= revfact[n - r];
  if (rs >= MOD) rs %= MOD;
  return rs;
}
void init() {
  fact[0] = 1, revfact[0] = 1;
  for (int i = 1; i < FACTSIZE; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
    revfact[i] = binpow(fact[i], MOD - 2, MOD);
  }
}
int modInv(int p) { return binpow(p, MOD - 2, MOD); }
#define MAXN 100100

//----//
int a[MAXN];
int arr[MAXN];
int arrS[MAXN];
int pSum[MAXN];
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  init();
  int N;
  cin >> N;
  REP(i, N) cin >> a[i];

  int valN = 1;
  REP(i, N) valN *= (i + 1), valN %= MOD;

  REPI(i, N) {
    pSum[i] += pSum[i - 1] + modInv(i);

    pSum[i] %= MOD;
  }

  int ans = 0;
  REP(i, N) {
    int val = pSum[N - i] + pSum[i + 1] + (MOD - 1);
    val %= MOD;
    val *= valN;
    val %= MOD;
    //    DUMP(i, val, N - i, i + 1, valN, (pSum[N - i] * valN) % MOD, (pSum[i + 1] * valN) % MOD);
    ans += a[i] * val;
    ans %= MOD;
  }

  print(ans);
}