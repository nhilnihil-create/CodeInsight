#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

const ll mod = 1000000007;

inline ll take_mod(ll a) { return (a % mod + mod) % mod; }

inline ll mul(ll a, ll b){
    return take_mod(a * b);
}

int main() {
  string str;
  cin >> str;

  size_t N = str.length();

  ll dp[N + 1][4];

  dp[0][0] = 1;
  dp[0][1] = 0;
  dp[0][2] = 0;
  dp[0][3] = 0;
  for (size_t i = 1; i <= N; i++) {
    if (str[i - 1] == 'A') {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
      dp[i][2] = dp[i - 1][2];
      dp[i][3] = dp[i - 1][3];
    } else if (str[i - 1] == 'B') {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1];
      dp[i][2] = dp[i - 1][2] + dp[i - 1][1];
      dp[i][3] = dp[i - 1][3];
    } else if (str[i - 1] == 'C') {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1];
      dp[i][2] = dp[i - 1][2];
      dp[i][3] = dp[i - 1][3] + dp[i - 1][2];
    } else {
      dp[i][0] = mul(3, dp[i - 1][0]);
      dp[i][1] = mul(3, dp[i - 1][1]) + dp[i - 1][0];
      dp[i][2] = mul(3, dp[i - 1][2]) + dp[i - 1][1];
      dp[i][3] = mul(3, dp[i - 1][3]) + dp[i - 1][2];
    }
    dp[i][0] = take_mod(dp[i][0]);
    dp[i][1] = take_mod(dp[i][1]);
    dp[i][2] = take_mod(dp[i][2]);
    dp[i][3] = take_mod(dp[i][3]);
  }

  cout << dp[N][3] << endl;

  return 0;
}