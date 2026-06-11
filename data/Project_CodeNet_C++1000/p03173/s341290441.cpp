#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  int N; cin >> N;
  vector<LL> S(N + 1); S[0] = 0;
  for (int i = 0; i < N; ++i) {
    LL a; cin >> a;
    S[i + 1] = S[i] + a;
  }

  vector<vector<LL>> dp(N + 1, vector<LL>(N + 1, 1e18));
  for (int i = 0; i <= N; ++i) dp[i][i] = 0;

  for (int j = 1; j <= N; ++j) {
    for (int i = 0; i + j <= N; ++i) {
      int l = i, r = i + j;
      LL merge_cost = S[r] - S[l - 1];
      for (int k = l; k < r; ++k) {  // dp[i][k] + dp[k+1][i+j]
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + merge_cost);
      }
    }
  }
  cout << dp[1][N] << endl;
}
