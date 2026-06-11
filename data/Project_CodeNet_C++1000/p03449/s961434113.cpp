#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int m[2][n];
    for(i=0;i<2;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>m[i][j];
        }
    }
    int dp[3][n+1];
    dp[0][0]=m[0][0];
    for(i=1;i<2;i++)
    {
        dp[i][0]=dp[i-1][0]+m[i][0];
    }
    for(i=1;i<n;i++)
    {
        dp[0][i]=dp[0][i-1]+m[0][i];
    }
    for(i=1;i<2;i++)
    {
        for(j=1;j<n;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+m[i][j];
        }
    }
    cout<<dp[1][n-1]<<endl;
    return 0;
}
