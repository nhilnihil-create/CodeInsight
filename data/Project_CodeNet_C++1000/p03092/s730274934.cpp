#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
ll A,B;
int a[5005];
ll dp[2][5005];
int now,last;
int high[5005],low[5005];
int main()
{
	scanf("%d%lld%lld",&n,&A,&B);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=1;j<i;j++)
			if(a[j]>a[i]) high[i]++;
				else low[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		last=now;
		now=!last;
		memset(dp[now],-1,sizeof dp[now]);
		dp[now][a[i]]=A*high[i]+B*low[i];
		for(int j=1;j<=n;j++)
		{
			if(dp[last][j]==-1) continue;
			if(a[i]>j) dp[now][j]=dp[last][j]+A;
			if(a[i]<j) dp[now][j]=dp[last][j]+B;
			if(a[i]>j) dp[now][a[i]]=min(dp[now][a[i]],dp[last][j]);
		}
	}
	ll ans=dp[now][1];
	for(int i=1;i<=n;i++)
		ans=min(ans,dp[now][i]);
	printf("%lld",ans);
	return 0;
}

