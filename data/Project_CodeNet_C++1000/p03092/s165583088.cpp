#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5050;
const ll inf=9e18;
ll dp[N];
int p[N],cnt[N];
int main()
{
	int n,A,B;
	scanf("%i %i %i",&n,&A,&B);
	for(int i=1;i<=n;i++) scanf("%i",&p[i]),dp[i]=inf;
	for(int i=1;i<=n;i++)
	{
		int lo=0,hi=0,mx=0;
		for(int j=i-1;j>=1;j--)
		{
			if(p[j]<p[i])
			{
				if(p[j]>mx)
				{
					mx=p[j];
					dp[i]=min(dp[i],dp[j]+(ll)lo*B+(ll)hi*A);
				}
				lo++;
			}
			else hi++;
			//printf("%i %i\n",p[j],p[i]);
		}
		if(lo==0) dp[i]=min(dp[i],(ll)hi*A);
		//printf("%i %lld hi:%i lo:%i\n",i,dp[i],hi,lo);
	}
	ll ans=inf;
	for(int i=n;i>=1;i--)
	{
		int lo=0,hi=0;
		for(int j=1;j<p[i];j++) lo+=cnt[j];
		for(int j=p[i]+1;j<=n;j++) hi+=cnt[j];
		ans=min(ans,dp[i]+(ll)lo*B+(ll)hi*A);
		cnt[p[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}