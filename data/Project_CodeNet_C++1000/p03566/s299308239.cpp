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
    cerr << v << " ";                                                          \
  }                                                                            \
  cerr << "\n";
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
  int N;
  cin >> N;
  vec< int > t(N + 1);
  vec< double > v(N);
  t[0] = 0;
  REP(i, N) {
    int p;
    cin >> p;
    t[i + 1] = t[i] + p;
  }
  REP(i, N) { cin >> v[i]; }
  vec< double > tLis(2 * t[N] + 1, INF);

  REP(i, (int)tLis.size()) {
    double val = i * .5;
    // int index = lower_bound(ALL(t), val) - t.begin();
    chmin(tLis[i], val);
    REP(j, N) {
      if (val < t[j]) {
        chmin(tLis[i], v[j] + t[j] - val);
      } else if (val > t[j + 1]) {
        chmin(tLis[i], v[j] + val - t[j + 1]);
      } else {
        chmin(tLis[i], v[j]);
      }
    }
    chmin(tLis[i], t[N] - val);
  }
  // PRINTALL(tLis);
  double sum = 0;
  REP(i, (int)tLis.size() - 1) { sum += (tLis[i] + tLis[i + 1]) * .25; }
  print(sum);
}