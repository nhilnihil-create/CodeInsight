#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
int n,a,b;
int p[5050];
int rev[5050];
ll dp[5050][5050];
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
		p[i]--;
		rev[p[i]]=i;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	if(rev[0]!=0)dp[0][n]=b;
	for(int i=1;i<n;i++)
	{
		dp[i][i]=min(dp[i][i],dp[i-1][n]);
		dp[i][n]=min(dp[i][n],dp[i-1][n]+b);
	//	cout<<i<<endl;
		for(int lst=0;lst<i;lst++)
		{
			if(rev[lst]<rev[i])
			{
				dp[i][i]=min(dp[i][i],dp[i-1][lst]);
				dp[i][lst]=min(dp[i][lst],dp[i-1][lst]+b);
			}
			else
			{
				dp[i][lst]=min(dp[i][lst],dp[i-1][lst]+a);
			}
		}
	}
	ll ans=linf;
	for(int i=0;i<=n;i++)
		ans=min(ans,dp[n-1][i]);
	printf("%lld\n",ans);
	return 0;
}