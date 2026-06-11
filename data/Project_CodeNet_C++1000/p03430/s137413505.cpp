#include <iostream>
using namespace std;
char a[1000];
int dp[305][305][305];
int main()
{
    int n = 0, m, ans = 0;
    cin >> a + 1;
    cin >> m;
    for(int i = 1; a[i] != 0; i ++)
        n = i;
    for(int i = 1; i <= n; i ++)
        for(int j = n ; j >= i; j --)
        {
            for(int k = 0; k <= m; k ++)
            {
                if(i == j)
                    dp[i][j][k] = dp[i - 1][j + 1][k] + 1;
                else
                {
                    if(k > 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k - 1] + 2);
                    if(a[i] == a[j])
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k] + 2);
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j + 1][k]);
                }
                //cout << i << " " << j << " " << k << "  " << dp[i][j][k] << endl;
                ans = max(ans, dp[i][j][k]);
            }
        }
    cout << ans;
    return 0;
}
