#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  const long long INF = 1LL << 60;
  
  long long dp[n];
  for (int i = 0; i < n; i++) dp[i] = INF;

  long long in[n];
  for (int i = 0; i < n; i++) cin >> in[i];

  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = max(0, i - k); j < i; j++) {
      dp[i] = min(dp[i], dp[j] + abs(in[j] - in[i]));
    }
  }
  cout << dp[n - 1] << endl;
}
