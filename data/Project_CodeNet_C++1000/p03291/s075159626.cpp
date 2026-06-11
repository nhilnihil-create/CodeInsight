#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    string S;
    cin >> S;
    int n = S.size();
    ll dp[n + 1][4] = {0};

    for (int i = n; i >= 0; --i)
    {
        for (int j = 3; j >= 0; --j)
        {
            if (i == n)
            {
                if (j == 3) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
            else
            {
                if (j == 3)
                {
                    if (S[i] == '?') dp[i][j] = 3 * dp[i + 1][j];
                    else dp[i][j] = dp[i + 1][j];
                }
                else
                {
                    // i番目に丸を付けない
                    if (S[i] == '?') dp[i][j] = 3 * dp[i + 1][j];
                    else dp[i][j] = dp[i + 1][j];
                    // i番目に丸を付ける
                    if (S[i] == '?') dp[i][j] += dp[i + 1][j + 1];
                    else if (S[i] == 'A' && j == 0) dp[i][j] += dp[i + 1][j + 1];
                    else if (S[i] == 'B' && j == 1) dp[i][j] += dp[i + 1][j + 1];
                    else if (S[i] == 'C' && j == 2) dp[i][j] += dp[i + 1][j + 1];
                }
            }
            
            dp[i][j] = dp[i][j] % MOD;
        }
    }

    cout << dp[0][0] << endl;
}
