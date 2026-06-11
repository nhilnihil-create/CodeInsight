#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
typedef long double ld;
const int INF = 1e9;
const ll MOD = 1000000007;
ld dp[4000][4000];
int main() {
  int N;
  cin >> N;
  vector<ld> p(N);
  REP(i, N) cin >> p[i];
  dp[0][0] = 1;
  REP(i, N) REP(j, N) {
    dp[i + 1][j] += dp[i][j] * (1 - p[i]);
    dp[i + 1][j + 1] += dp[i][j] * p[i];
  }
  ld ans = 0;
  for (int i = (N / 2 + 1); i <= N; i++) {
    ans += dp[N][i];
  }
  cout << fixed << setprecision(10) << ans << endl;
}