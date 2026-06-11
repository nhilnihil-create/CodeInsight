#include <bits/stdc++.h>
using namespace std;

// dp[i][j][k] :=     i: 上位 i 桁目まで決定
//                    j: small(数字を自由に選べる)か
//                    k: {3,5,7} を選んだかのflag
//                    の条件を満たす数値の数
int dp[11][2][8];

int main()
{
  cin.tie(0); ios::sync_with_stdio(false);

  string n;
  cin >> n;

  int len = n.size();
  dp[0][0][0] = 1;

  for (int i = 0; i < len; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      for (int k = 0; k < 8; ++k)
      {
        if (!dp[i][j][k]) continue;

        if (j == 1)                  // small ([0, 9] から数字を選べる)か
        {
          if (!k) dp[i + 1][1][0] += dp[i][1][0];

          dp[i + 1][1][k | 1] += dp[i][1][k];              // +3
          dp[i + 1][1][k | 2] += dp[i][1][k];              // +5
          dp[i + 1][1][k | 4] += dp[i][1][k];              // +7
        }
        else                         // not small ([0, d] から数字を選べる)か
        {
          int d = n[i] - '0';

          if (!k)     dp[i + 1][1][0]     += dp[i][0][0];

          if (d == 3) dp[i + 1][0][k | 1] += dp[i][0][k];  // +3
          if (3 < d)  dp[i + 1][1][k | 1] += dp[i][0][k];  // +3
          if (d == 5) dp[i + 1][0][k | 2] += dp[i][0][k];  // +5
          if (5 < d)  dp[i + 1][1][k | 2] += dp[i][0][k];  // +5
          if (d == 7) dp[i + 1][0][k | 4] += dp[i][0][k];  // +7
          if (7 < d)  dp[i + 1][1][k | 4] += dp[i][0][k];  // +7
        }
      }
    }
  }

  int ans = dp[len][0][7] + dp[len][1][7];
  cout << ans << endl;
//  Debug Coding 
/*for (int i = 0; i <= len; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 8; ++k)
        if (dp[i][j][k])
        {
          cout << "dp[" << i << "][" << j << "][" << k << "] = (";
          cout << dp[i][j][k] << ")" << endl;
        }
*/
  return 0;
}