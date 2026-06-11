#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[100];
int M = 1000000007;
int dp[101][100001] = {};
int pre[100001] = {};


int main(void)
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = k; j >= 0; j--)
        {
            if (i == n - 1)
            {
                if (arr[i] < j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
                continue;
            }
            // for (int l = j; l >= max(0, j - arr[i]); l--)
            // {
            //     dp[i][j] = (dp[i][j] + dp[i + 1][l]) % M;
            // }
            if (j == k)
                dp[i][j] = pre[max(0, j - arr[i])];
            else
                dp[i][j] = (pre[max(0, j - arr[i])] - pre[j + 1]);
            dp[i][j] %= M;
        }
        pre[k] = dp[i][k];
        for (int j = k - 1; j >= 0; j--)
        {
            pre[j] = (pre[j + 1] + dp[i][j]) % M;
        }
        
    }
    // int sum = 0;
    // for (int i = k; i >= max(0, k - arr[0]); i--)
    //     sum = (sum + dp[0][i]) % M;
    if  (dp[0][k] < 0)
        dp[0][k] += M;
    printf("%d", dp[0][k]);
    
}