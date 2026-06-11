#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const long long LINF = 1000000000000000018ll;
const int INF = 1000000009;
const int mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << fixed;

  string s; cin >> s;
  // dp[i][x] := i文字までみたとき,
  // dp[i][0]: Aが何個あるか?
  // dp[i][1]: ABが何個あるか?
  // dp[i][2]: ABCが何個あるか?
  vector<vector<long long>> dp(s.length()+10, vector<long long>(3, 0));
  // mul: 文字列として考えられる種類 "?" があると3倍される
  long long mul = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A') {
      dp[i+1][0] = dp[i][0] + mul;
      dp[i+1][1] = dp[i][1];
      dp[i+1][2] = dp[i][2];
    }
    if (s[i] == 'B') {
      dp[i+1][0] = dp[i][0];
      dp[i+1][1] = dp[i][1] + dp[i][0];
      dp[i+1][2] = dp[i][2];
    }
    if (s[i] == 'C') {
      dp[i+1][0] = dp[i][0];
      dp[i+1][1] = dp[i][1];
      dp[i+1][2] = dp[i][2] + dp[i][1];
    }
    if (s[i] == '?') {
      // ?のときは, 3つの構成可能文字列に分岐するので, 3倍する
      dp[i+1][0] = dp[i][0] * 3 + mul;
      dp[i+1][1] = dp[i][1] * 3 + dp[i][0];
      dp[i+1][2] = dp[i][2] * 3 + dp[i][1];
      mul = (mul * 3) % mod;
    }
    dp[i+1][0] %= mod;
    dp[i+1][1] %= mod;
    dp[i+1][2] %= mod;
  }
  cout << dp[s.length()][2] << endl;
  return 0;
}