#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int dp[N+1];
  dp[0] = 0;
  for (int i = 1; i <= N; i++) {
    dp[i] = dp[i-1]+1;
    for (int j = 6; i-j >= 0; j *= 6) {
      dp[i] = min(dp[i],dp[i-j]+1);
    }
    for (int j = 9; i-j >= 0; j*= 9) {
      dp[i] = min(dp[i],dp[i-j]+1);
    }
  }
  cout << dp[N];
}