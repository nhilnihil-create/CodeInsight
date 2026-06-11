#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  string S;
  ll N, K;
  cin >> S >> K;
  N = S.length();

  ll dp[N][N][K + 1];
  REP(l, 0, N) REP(r, l, N) REP(k, 0, K + 1) dp[l][r][k] = 0;
  REP(l, 0, N) REP(k, 0, K + 1) dp[l][l][k] = 1;
  REP(l, 0, N - 1) if(S[l] == S[l + 1]) dp[l][l + 1][0] = 2;
  REP(l, 0, N - 1) REP(k, 1, K + 1) dp[l][l + 1][k] = 2;
  REP(s, 0, N) REP(l, 0, N - s) {
    ll r = l + s;
    REP(k, 0, K + 1) {
      if(l + 1 <= r - 1 && S[l] == S[r]) dp[l][r][k] = max(dp[l][r][k], dp[l + 1][r - 1][k] + 2);
      if(l + 1 <= r) dp[l][r][k] = max(dp[l][r][k], dp[l + 1][r][k]);
      if(l <= r - 1) dp[l][r][k] = max(dp[l][r][k], dp[l][r - 1][k]);
      if(k > 0 && l + 1 <= r - 1) dp[l][r][k] = max(dp[l][r][k], dp[l + 1][r - 1][k - 1] + 2);
      if(k > 0 && l + 1 <= r) dp[l][r][k] = max(dp[l][r][k], dp[l + 1][r][k - 1]);
      if(k > 0 && l <= r - 1) dp[l][r][k] = max(dp[l][r][k], dp[l][r - 1][k - 1]);
      if(k > 0) dp[l][r][k] = max(dp[l][r][k], dp[l][r][k - 1]);
    }
  }
  cout << dp[0][N - 1][K] << endl;
}
