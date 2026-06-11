#include <bits/stdc++.h>
using namespace std;
#define maxn (1<<26)+1
#define maxm (int)2e5+2
int dp[maxn];
char s[maxm];
#define INF 0x7f7f7f
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	memset(dp,INF,sizeof(dp));
	long long now=0;
	dp[now]=0;
	for (int i=0;i<n;i++)
	{
		now^=(1<<(s[i]-'a'));
		for (int j=0;j<=25;j++)
		  if ((now^(1<<j))!=now) dp[now]=min(dp[now],dp[now^(1<<j)]+1);
	}
	if (now==0) dp[now]=1;
	printf("%d\n",dp[now]);
}