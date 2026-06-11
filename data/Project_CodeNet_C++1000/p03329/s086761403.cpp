#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin >> N;
  vector<int> dp(N + 1, N);
  dp[0] = 0;
  for (int i = 0; i <= N; i++) {
    dp[i] = min(dp[i], dp[i - 1] + 1);
    for (int pow6 = 6; pow6 <= min(N, i); pow6 *= 6)
      dp[i] = min(dp[i], dp[i - pow6] + 1);
    for (int pow9 = 9; pow9 <= min(N, i); pow9 *= 9)
      dp[i] = min(dp[i], dp[i - pow9] + 1);
  }

  cout << dp[N] << endl;
}
