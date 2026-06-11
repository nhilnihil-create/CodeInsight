#include<iostream>
#include<string>
using namespace std;

unsigned long mod = 1000000007;
unsigned long dp[1000010][4];

int main() {
  string s;
  cin >> s;
  int s_len = (int)s.length();
  dp[s_len][3] = 1;
  dp[s_len][2] = 0;
  dp[s_len][1] = 0;
  dp[s_len][0] = 0;
  string abc = "ABC";
  for (int i=s_len-1; i>=0; i--) {
    for (int j=3; j>=0; j--) {
      if (j == 3 && s[i] == '?') {
        dp[i][j] = (3 * dp[i+1][j]) % mod;
      } else if (j == 3) {
        dp[i][j] = (1 * dp[i+1][j]) % mod;
      } else if (s[i] == '?') {
        dp[i][j] = (3 * dp[i+1][j] + 1 * dp[i+1][j+1]) % mod;
      } else if (s[i] == abc[j]) {
        dp[i][j] = (1 * dp[i+1][j] + 1 * dp[i+1][j+1]) % mod;
      } else {
        dp[i][j] = (1 * dp[i+1][j]) % mod;
      }
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}

