#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >>m;
    char inp[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin >> inp[i][j];
    }
    int dp[n][m];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        if(inp[0][i]=='.')
        dp[0][i]=1;
        else
        break;
    }
    for(int i=0;i<n;i++)
    {
        if(inp[i][0]=='.')
        dp[i][0]=1;
        else
        break;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(inp[i][j]=='#')
            continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
        }
    }
    cout << dp[n-1][m-1] << endl;
    
    return 0;
}