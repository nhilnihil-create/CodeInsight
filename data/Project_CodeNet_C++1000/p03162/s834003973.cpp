#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> p(n+1, vector<int>(3));
  rep(i,n) rep(j,3) cin >> p[i][j];
  vector<vector<ll>> dp(n+1, vector<ll>(3));
  rep(i,n) rep(j,3) rep(k,3) {
    if(j == k) continue;
    dp[i+1][j] = max(dp[i+1][j], dp[i][k] + p[i][j]);
  }
  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
  return 0;
}
