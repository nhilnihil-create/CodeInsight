#include <iostream>
#include <string>

using namespace std;

const int M = 1e9+7;

int n;
string s;

long long dp[3005][3005];

int main()
{
  cin >> n >> s;
  
  dp[1][1] = 1;

  for (int i = 1; i < n; i++) {
    long long sum = 0;
    if (s[i-1] == '<') {
      for (int j = 2; j <= i+1; j++) {
        sum = (sum + dp[i][j-1]) % M;
        dp[i+1][j] = sum;
      }
    } else {
      for (int j = i; j >= 1; j--) {
        sum = (sum + dp[i][j]) % M;
        dp[i+1][j] = sum;
      }
    }
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + dp[n][i]) % M;
  }
  
  cout << ans << endl;
  return 0;
}