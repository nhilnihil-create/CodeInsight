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

int main()
{
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) for(int k=0;k<(1<<n);k++)
		if(((1<<i)&k)&&((1<<j)&k)) score[k]+=a[i][j];
	for(int i=1;i<(1<<n);i++)
	{
		int now=i;
		do
		{
			dp[i]=max(dp[i],dp[now]+score[i-now]);
			now=(now-1)&i;
		} while(now!=i);
	}
	printf("%lld\n",dp[(1<<n)-1]);
	return 0;
}

