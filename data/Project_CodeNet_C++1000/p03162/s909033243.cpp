#include<bits/stdc++.h>
using namespace std;
int dp[100001][3];
int a[100001][3];
int solve(int n)
{
    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=max(dp[i-1][1]+a[i][0],dp[i-1][2]+a[i][0]);
        dp[i][1]=max(dp[i-1][0]+a[i][1],dp[i-1][2]+a[i][1]);
        dp[i][2]=max(dp[i-1][0]+a[i][2],dp[i-1][1]+a[i][2]);
    }
    int mx=max(dp[n-1][0],dp[n-1][1]);
    return max(mx,dp[n-1][2]);
}
int main()
{
        int n;
        cin >> n;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<3;k++)
            cin >> a[j][k];
        }
        cout << solve(n) << endl;
}