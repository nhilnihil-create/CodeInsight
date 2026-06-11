#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  const long long INF = 1LL << 60;
  long long dp[n+1];
  for (int i = 0; i < n + 1; i++) dp[i] = INF;

  long long in[n];
  for (int i = 0; i < n; i++) cin >> in[i];

  dp[0] = 0;
  for (int i = 0; i < (n - 1); i++) {
    dp[i + 1] = min(dp[i + 1], dp[i] + abs(in[i] - in[i+1]));
    dp[i + 2] = min(dp[i + 2], dp[i] + abs(in[i] - in[i+2]));
  }

  cout << dp[n - 1];
}

