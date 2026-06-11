#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define li long
#define pb push_back
#define mem(arr,x) memset(arr,x,sizeof(arr))

ll a[101],n;
ll dp[101][100001];

ll totalWays(ll start,ll k)
{
	if(k==0) return 1;
	if(start<0) return 0;
	if(dp[start][k]!=0) return dp[start][k];
	ll i,ans=0;
	for(i=0;i<=min(a[start],k);i++)
	{
		if(k-i>=0)
		ans=(ans%MOD+totalWays(start-1,k-i)%MOD)%MOD;
	}
	return dp[start][k]=ans%MOD;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k,i,j,l;
    cin>>n>>k;
    for(i=0;i<n;i++)
    	cin>>a[i];

    mem(dp,0);

    // top-down
    // cout<<totalWays(n-1,k)<<endl;

    dp[0][0]=1;
    for(i=1;i<=k;i++) dp[0][i]+=dp[0][i-1];

    for(i=1;i<=n;i++)
    {
    	for(j=0;j<=k;j++)
    	{
    		if(j-a[i-1]>0)
    			dp[i][j]=(dp[i-1][j]%MOD-dp[i-1][j-a[i-1]-1]%MOD+MOD)%MOD;
    		else
    			dp[i][j]=dp[i-1][j]%MOD;
    	}
    	for(j=1;j<=k;j++)
    	{
    		dp[i][j]+=dp[i][j-1];
    		dp[i][j]%=MOD;
    	}
    }
    // for(i=0;i<=n;i++)
    // {
    // 	for(j=0;j<=k;j++)
    // 		cout<<dp[i][j]<<" ";
    // 	cout<<endl;
    // }
    cout<<(dp[n][k]-dp[n][k-1]+MOD)%MOD;
    return 0;
}