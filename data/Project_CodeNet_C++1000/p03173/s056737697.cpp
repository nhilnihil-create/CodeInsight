#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  long long a[N], sums[N+1];
  vector<vector<long long>> dp(N,vector<long long>(N,LLONG_MAX));
  sums[0] = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sums[i+1] = sums[i]+a[i];
    dp[i][i] = 0;
  }
  for (int i = N-1; i+1; i--) {
    for (int j = i+1; j < N; j++) {
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][k]+dp[k+1][j]+sums[j+1]-sums[i],dp[i][j]);
      }
    }
  }
  cout << dp[0][N-1];
}