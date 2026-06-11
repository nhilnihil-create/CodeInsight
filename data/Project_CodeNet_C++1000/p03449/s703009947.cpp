#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  int dp[2][101];
  dp[0][0] = 0;
  dp[1][0] = 0;
  repe(i, 1, n) {
    cin >> dp[0][i];
    dp[0][i] += dp[0][i - 1];
  }
  repe(i, 1, n) {
    cin >> dp[1][i];
    dp[1][i] += max(dp[1][i - 1], dp[0][i]);
  }
  cout << dp[1][n] << endl;

  return 0;
}
