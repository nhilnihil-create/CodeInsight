#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define BITF(n, i) (((n) >> i) & 1)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, n) for (auto &&i : n)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define DEBUG(x) cerr << #x << ": " << x << "\n"
#define DEBUG2(x, y) cerr << #x << ": " << x << " " << #y << ": " << y << "\n"
#define DEBUG3(x, y, z) cerr << #x << ": " << x << " " << #y << ": " << y << " " << #z << ": " << z << "\n"
#define PRINTALL(V)    \
  for (auto v : (V)) { \
    cerr << v << " ";  \
  }                    \
  cerr << "\n";
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
template <class T> void print2(const T &x, const T &y) { cout << x << " " << y << "\n"; }
template <class T> void print3(const T &x, const T &y, const T &z) { cout << x << " " << y << " " << z << "\n"; }
const int MOD = 1000000007, MOD2 = 998244353, INF = 1061109567, INF2 = INF * INF;
const double EPS = 1e-10, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
vec<pint> a, b;
int N;
vec<pint> memo(int id) {
  if (b[id * 2].fst != INF) {
    vec<pint> tmp = {b[id * 2], b[id * 2 + 1]};
    return tmp;
  } else {
    set<pint> lis;
    lis.insert(a[id]);
    lis.insert(pint(INF, INF));
    REP(i, N) {
      if (BITF(id, i)) {
        vec<pint> tmp(memo(id - BIT(i)));
        lis.insert(tmp[0]);
        lis.insert(tmp[1]);
      }
    }
    //   sort(ALL(lis));
    //   reverse(ALL(lis));
    auto itr = lis.begin();
    auto itr2 = itr;
    itr2++;
    // DEBUG(id);
    // FORA(e, lis) DEBUG2(e.fst, e.snd);
    // cout << "\n";
    vec<pint> tmp = {*itr, *itr2};
    b[id * 2] = tmp[0];
    b[id * 2 + 1] = tmp[1];
    return tmp;
  }
}
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  cin >> N;
  a.resize(BIT(N));
  b.resize(2 * BIT(N), pint(INF, INF));
  REP(i, BIT(N)) {
    cin >> a[i].fst;
    a[i].fst *= -1;
    a[i].snd = i;
  }
  int val = 0;
  REPS(i, BIT(N) - 1) {
    // DEBUG(i);
    vec<pint> tmp(memo(i));
    int tmpval = -tmp[0].fst - tmp[1].fst;
    chmax(val, tmpval);
    print(val);
  }
  //  REPS(i, BIT(N) - 1) { DEBUG2(b[2 * i].fst, b[2 * i + 1].fst); }
}
/*
答え比較にエラーあり。
*/