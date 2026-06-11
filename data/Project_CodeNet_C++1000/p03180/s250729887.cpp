#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
#define endl '\n'
#define F first
#define S second
#define lowbit(x) (__builtin_ffs(x)-1)
const int MAX_N=20;

int n;
int a[MAX_N][MAX_N];
ll score[1<<MAX_N];
ll dp[1<<MAX_N];

ll getans(int mask)
{
	if(~dp[mask]) return dp[mask];
	dp[mask]=0;
	int MAX=(1<<__builtin_popcount(mask));
	for(int i=1,b;i<MAX;i++)
	{
		b=0;
		for(int j=1,cnt=1;j<=mask;j<<=1) if(j&mask)
		{
			if(cnt&i) b|=j;
			cnt<<=1;
		}
		dp[mask]=max(dp[mask],getans(mask^b)+score[b]);
	}
	return dp[mask];
}

int main()
{
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<(1<<n);i++)
	{
		int low=lowbit(i);
		score[i]=score[i^(1<<low)];
		for(int j=0;(1<<j)<=i;j++) if((1<<j)&i) score[i]+=a[low][j];
	}
	printf("%lld\n",getans((1<<n)-1));
	return 0;
}

