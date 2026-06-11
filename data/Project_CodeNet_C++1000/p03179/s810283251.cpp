#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18 + 7

const int mod = (int)1e9+7;

int dp[2][3010] = {0};
int sum[2][3010] = {0};

int getsum(int len, int whobeg, int whofin) {
  int res = sum[len & 1][whofin] - sum[len & 1][whobeg - 1];
  if (res < 0) res += mod;
  return res;
}

signed main() {

  int n;
  cin >> n;
  string s;
  cin >> s;
  
  int len = 1;
  dp[len & 1][1] = 1;
  sum[len & 1][1] = 1;
  for (len = 2; len <= n; len ++) {
    char flag = s[len - 2];
    for (int who = 1; who <= len; who ++) {
      if (flag == '>') {
        dp[len & 1][who] = getsum(len - 1, who, len - 1);
      } else {
        dp[len & 1][who] = getsum(len - 1, 1, who - 1);
      }
      sum[len & 1][who] = (sum[len & 1][who - 1] + dp[len & 1][who]) % mod;
    }
  }
  cout << sum[n & 1][n] << endl;
  return 0;
}