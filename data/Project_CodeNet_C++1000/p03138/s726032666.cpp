#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

ll solve(const ll K, const vector<ll> A) {
  vector<vector<ll>> dp(50, vector<ll>(2, -1));

  ll ans = 0;
  for (int i = 45; i >= 0; i--) {
    ll n = (1LL << i);
    if (n > K) {
      ll sum = 0;
      for (auto &&e : A) {
        if (bitset<64>(e)[i]) {
          sum += n;
        }
      }
      ans += sum;
    }
  }

  for (int i = 45; i >= 0; i--) {
    ll n = (1LL << i);
    if (n > K) {
      continue;
    }

    ll sum1 = 0;
    ll sum2 = 0;
    for (auto &&e : A) {
      if (bitset<64>(e)[i] ^ 1) {
        sum1 += n;
      } else {
        sum2 += n;
      }
    }

    if (dp[i + 1][0] == (-1) && dp[i + 1][1] == (-1)) {
      dp[i][0] = sum1;
      dp[i][1] = sum2;
      continue;
    }

    // 0 -> 0
    if (bitset<64>(K)[i]) {
      dp[i][0] = max(dp[i][0], dp[i + 1][0] + sum1);
    } else {
      dp[i][0] = max(dp[i][0], dp[i + 1][0] + sum2);
    }

    // 1 -> 1
    dp[i][1] = max(dp[i][1], max(dp[i + 1][1] + sum1, dp[i + 1][1] + sum2));

    // 0 -> 1
    if (bitset<64>(K)[i]) {
      dp[i][1] = max(dp[i][1], dp[i + 1][0] + sum2);
    }
  }

  return ans + max(0LL, max(dp[0][0], dp[0][1]));
}

int main() {
  ll n, K;
  cin >> n >> K;

  vector<ll> A(n);
  for (size_t i = 0; i < n; i++) {
    cin >> A[i];
    // cout << (bitset<64>(A[i])[0] ^ 0) << endl;
  }

  ll ans = max(ans, solve(K, A));
  cout << ans << endl;
}