#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

constexpr int64_t one = 1;

int main() {
  int64_t N, K;
  cin >> N >> K;
  vector<int64_t> nums(N);
  for (int64_t n = 0; n < N; ++n) {
    cin >> nums[n];
  }
  
  vector<vector<int64_t>> dp(2, vector<int64_t>(42, -1));
  dp[0][0] = 0;
  for (int d = 0; d <= 40; ++d) {
    int64_t digit = 40 - d;
    int64_t mask = one << digit;
    int64_t ones = 0, zeros = 0;
    for (int64_t n = 0; n < N; ++n) {
      if (nums[n] & mask) {
        ++ones;
      } else {
        ++zeros;
      }
    }
    if (K & mask) {
      dp[0][d+1] = dp[0][d] + zeros * mask;
      dp[1][d+1] = dp[0][d] + ones * mask;
      if (dp[1][d] != -1) {
        dp[1][d+1] = max(dp[1][d+1], 
                         max(dp[1][d] + ones * mask, dp[1][d] + zeros * mask));
      }
    } else {
      dp[0][d+1] = dp[0][d] + ones * mask;
      if (dp[1][d] != -1) {
        dp[1][d+1] = dp[1][d] + max(ones * mask, zeros * mask);
      }
    }
  }
  cout << max(dp[0][41], dp[1][41]) << endl;

  return 0;
}
