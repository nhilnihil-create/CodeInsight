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
const int MOD = 1000000007, INF = 1061109567;
const double EPS = 1e-10, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  string S;
  cin >> S;
  int N = S.size();
  /*REPR(i, N) {
    REP(j, N - i + 1) {
      if (S[j] == '1') {
        REP(k, i) { S[j + k] = (S[j + k] == '0') ? '1' : '0'; }
      }
    }
    DEBUG(S);
    if (count(ALL(S), '1') == 0) {
      print(i);
      break;
    }
  }*/
  /*  int halfN = N / 2;
    int ans = halfN;
    int a[2] = {0, 0};
    if (N % 2 == 1) {
      a[S[halfN] - '0']++;
    }
    REPR(i, halfN - 1) {
      a[S[i] - '0']++;
      a[S[N - 1] - '0']++;
      if (a[0] > 0 && a[1] > 0) {
        ans = halfN - 1 - i;
        break;
      }
    }
  print(ans + halfN + ((N % 2 == 0) ? 0 : 1));
    */
  int ans = N;
  REP(i, N - 1) {
    if (S[i] != S[i + 1]) {
      chmin(ans, max(i + 1, N - 1 - i));
    }
  }
  print(ans);
}