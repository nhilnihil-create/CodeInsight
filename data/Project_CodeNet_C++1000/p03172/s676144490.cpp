#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[102][100005],n;
int a[102],k;
signed main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    dp[0][0]=1;
    for(int j=0;j<=k;j++)
    {
    for(int i=1;i<=n;i++)
    {
            dp[i][j]=dp[i-1][j];
            if(j)
                dp[i][j]+=dp[i][j-1];
                dp[i][j]%=mod;
            if(j-a[i]-1>=0)
            dp[i][j]=(dp[i][j]+mod-dp[i-1][j-a[i]-1])%mod;
            dp[i][j]%=mod;
    }
    }
    cout<<dp[n][k]<<endl;
	return 0;
}
