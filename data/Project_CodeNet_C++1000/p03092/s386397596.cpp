#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define REP(i, a) for (int i = 0; i < (a); i++)
#define REPR(i, a) for (int i = (int)(a) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, a, b) for (int i = (int)(b) - 1; i >= a; i--)
#define ALL(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;
using vs = vector<string>;
int si() { int x; scanf("%d", &x); return x; }
long long sl() { long long x; scanf("%lld", &x); return x; }
string ss() { string x; cin >> x; return x; }
void pi(int x) { printf("%d ", x); }
void pl(long long x) { printf("%lld ", x); }
void pd(double x) { printf("%.15f ", x); }
void ps(const string &a) { cout << a << ' '; }
void br() { putchar('\n'); }

void to(long long *x, long long y) {
  *x = min(*x, y);
}

int main() {
  int N = si();
  long long R = sl();
  long long L = sl();
  vi A(N);
  REP(i, N) A[i] = si();
  static long long dp[5001][5001];
  REP(i, 5001) REP(j, 5001) dp[i][j] = 1e18;
  dp[0][0] = 0;
  REP(i, N) {
    REP(j, N+1) {
      if (j < A[i]) {
        to(&dp[i+1][A[i]], dp[i][j]);
        to(&dp[i+1][j], dp[i][j] + R);
      }
      if (A[i] < j) {
        to(&dp[i+1][j], dp[i][j] + L);
      }
    }
  }
  long long ans = 1e18;
  REP(i, N+1) to(&ans, dp[N][i]);
  cout << ans << '\n';
}
