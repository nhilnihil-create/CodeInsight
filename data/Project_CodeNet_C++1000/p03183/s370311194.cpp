#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n;
long long dp[N],ans;
struct node{int w,s;long long v;}a[N];

bool cmp(node x,node y){return x.w+x.s<y.w+y.s;}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%lld",&a[i].w,&a[i].s,&a[i].v);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i].s;j>=0;j--)
		{
			dp[j+a[i].w]=max(dp[j+a[i].w],dp[j]+a[i].v);
			ans=max(ans,dp[j+a[i].w]);
		}
	}
	printf("%lld\n",ans);
}