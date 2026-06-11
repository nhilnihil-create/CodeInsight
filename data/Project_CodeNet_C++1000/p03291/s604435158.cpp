#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<vector<ll>> dp(N + 1, vector<ll>(4));
  dp[N][3] = 1;
  for (int i = N - 1; i >= 0; i--) {
    int a = (S[i] == '?') ? 3 : 1, b;
    dp[i][3] = a * dp[i + 1][3] % MOD;
    b = (S[i] == '?') || (S[i] == 'C');
    dp[i][2] = (a * dp[i + 1][2] + b * dp[i + 1][3]) % MOD;
    b = (S[i] == '?') || (S[i] == 'B');
    dp[i][1] = (a * dp[i + 1][1] + b * dp[i + 1][2]) % MOD;
    b = (S[i] == '?') || (S[i] == 'A');
    dp[i][0] = (a * dp[i + 1][0] + b * dp[i + 1][1]) % MOD;
  }
  cout << dp[0][0] % MOD << endl;
}

/*
int main() {
  string S;
  cin >> S;
  ll ans = 0;
  ll a = 0, ab = 0, num = 1;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'A') {
      a = (a + num) % MOD;
    } else if (S[i] == 'B') {
      ab = (ab + a) % MOD;
    } else if (S[i] == 'C') {
      ans = (ans + ab) % MOD;
    } else {
      ans = (ans * 3 + ab) % MOD;
      ab = (ab * 3 + a) % MOD;
      a = (a * 3) % MOD + num;
      num = num * 3 % MOD;
    }
  }
  cout << ans % MOD << endl;
}
*/