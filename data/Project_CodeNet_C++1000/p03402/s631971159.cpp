#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, n) for (auto &&i : n)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define DEBUG(x) cerr << #x << ": " << x << "\n"
#define PRINTALL(V)                                                            \
  for (auto v : (V)) {                                                         \
    cout << v << " ";                                                          \
  }                                                                            \
  cout << "\n";
#define ALL(v) v.begin(), v.end()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define epb emplace_back
#define int long long
using namespace std;
template < class T > bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template < class T > bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template < class T > using vec = std::vector< T >;
template < class T > void print(const T &x) { cout << x << "\n"; }
const int MOD = 1000000007, INF = 1061109567;
const double EPS = 1e-10, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int A, B;
  cin >> A >> B;
  vec< vec< char > > T(100, vec< char >(100, '.'));
  REP(i, 50) {
    REP(j, 100) { T[i][j] = '#'; }
  }
  A--, B--;

  REP(i, A) {
    int x = i % 50;
    int y = i / 50;
    T[y * 2][2 * x] = '.';
  }
  REP(i, B) {
    int x = i % 50;
    int y = i / 50;
    T[51 + y * 2][2 * x] = '#';
  }
  cout << 100 << " " << 100 << "\n";
  REP(i, 100) {
    REP(j, 100) { cout << T[i][j]; }
    cout << "\n";
  }
}