#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> h(N+1), dp(N+1, 1 << 30);
  dp[1] = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> h[i];
    for (int j = max(1, i-K); j != i; ++j) {
      dp[i] = min(dp[i],dp[j] + abs(h[i]-h[j]));
    }
  }
  cout << dp[N] << endl;
}
