#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main()
{
    setprecision(20);
    int n;
    cin>>n;
    vector<long double> coins(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>coins[i];
    }
    vector<vector<long double> > dp(n+1,vector<long double>(n+1,0));
    dp[0][0]=1.0;
    // dp[1][0]=1-coins[1];
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0]*(1-coins[i]);
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=coins[i]*dp[i-1][j-1]+(1-coins[i])*dp[i-1][j];
        }
    }
    long double ans=0;
    for(int i=0;i<=n;i++)
    {
        if(i>n-i)
        {
            ans+=dp[n][i];
        }
    }
    cout<<setprecision(20)<<ans;
}