#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

ll dp[N][3] = {};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  string s;
  cin >> s;
  int n = s.length();

  ll p = 1;
  if (s[0] == 'A' || s[0] == '?') dp[0][0] = 1;
  if (s[0] == '?') p = 3;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i][j] = dp[i - 1][j] * (s[i] == '?' ? 3 : 1);
      if ("ABC"[j] == s[i] || s[i] == '?') {
        if (j == 0) dp[i][j] += p;
        else dp[i][j] += dp[i - 1][j - 1];
      }
      dp[i][j] %= mod;
    }
    if (s[i] == '?') p = (p * 3) % mod;
  }

  cout << dp[n - 1][2] << '\n';
}
