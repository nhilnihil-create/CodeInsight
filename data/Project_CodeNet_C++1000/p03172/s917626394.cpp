#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        int m = 1e9 + 7;
    int dp[n + 1][k + 1];
    int ans = 0;
    memset(dp, 0, sizeof(dp));
   for(int i=0;i<=arr[0];i++)
    dp[0][i] = 1;
    for (int i = 1; i < n; i++)
    {  
         int pre[k+1] = {0,};
         pre[0] = dp[i-1][0];
    for(int j = 1;j<=k;j++)
        pre[j] = (pre[j-1] + dp[i-1][j]) % m;
        for (int j = 0; j <= k; j++)
        {   if(j > arr[i])
            dp[i][j] = (pre[j] + m - pre[j-arr[i] - 1])%m;
            else
            {
                dp[i][j] = pre[j];
            }
            
        }
    }
    cout << dp[n-1][k] << endl;
}