// review
#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAXN= 1e5+10;

string s;
ll dp[MAXN][4];

void solve() {
  dp[s.size()][3] = 1;
  for (int i=s.size();i>=0;i--) {
    for (int j=3;j>=0;j--) {
      if (i == s.size()) {
        dp[i][j] = j == 3 ? 1 : 0;
      } else {
        dp[i][j] = dp[i+1][j] * (s[i] == '?' ? 3 : 1);
        if (j < 3 && (s[i] == '?' || s[i] == "ABC"[j])) {
          dp[i][j] += dp[i+1][j+1];
        }
        dp[i][j] %= MOD;
      }
    }
  }

  cout << dp[0][0] << endl;
}

int main() {
  cin >> s;
  solve();
}
