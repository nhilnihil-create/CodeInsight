#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
const int maxm=1<<26;
#define INF 0x3f3f3f3f
int dp[maxm];
char s[maxn];
int idx(char x)
{
	int ans=x-'a';
	return 1<<ans;
}
int main()
{
	memset(dp,INF,sizeof(dp));
	cin>>s;
	int n=strlen(s);
	dp[0]=0;
	int now=idx(s[0]);
	dp[now]=1;
	for (int i=1;i<n;i++)
	{
		now^=idx(s[i]);
		for (int j=0;j<=25;j++)
		{
			if (now^(1<<j)!=now) dp[now]=min(dp[now],dp[now^(1<<j)]+1);
		}
	}
	if (now==0) dp[now]=1;
	printf("%d\n",dp[now]);
	return 0;
}