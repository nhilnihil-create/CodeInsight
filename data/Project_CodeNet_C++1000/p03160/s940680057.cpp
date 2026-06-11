#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> h(N + 1), dp(N + 1);
  dp[0] = 1 << 30;
  cin >> h[1];
  for (int i = 2; i <= N; ++i) {
    cin >> h[i];
    dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                dp[i - 2] + abs(h[i] - h[i - 2]));
  }
  cout << dp[N] << endl;
}
