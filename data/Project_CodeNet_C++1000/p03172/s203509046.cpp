#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 int a[105];
 int dp[101][100002];
 int n,k;
signed main()
{


    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=mod;
            if(j)
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
            if(j-a[i]-1>=0)
            {
                dp[i][j]+=mod;
            dp[i][j]-=dp[i-1][j-a[i]-1];
            dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[n][k]<<endl;
	return 0;
}
