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
constexpr LL kInf = 1e18;

string S;
int L;

int main() {
  cin >> S;
  L = S.size();
  vector<vector<LL>> dp(L + 1, vector<LL>(4));
  dp[0][0] = 1;
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (S[i] != '?') dp[i + 1][j] = dp[i][j];
      else             dp[i + 1][j] = dp[i][j] * 3;
      dp[i + 1][j] %= kMod;
    }

    if (S[i] == 'A' || S[i] == '?') dp[i + 1][1] += dp[i][0];
    if (S[i] == 'B' || S[i] == '?') dp[i + 1][2] += dp[i][1];
    if (S[i] == 'C' || S[i] == '?') dp[i + 1][3] += dp[i][2];

    for (int j = 0; j < 4; ++j) {
      dp[i + 1][j] %= kMod;
    }
  }
  cout << dp[L][3] << endl;
}
