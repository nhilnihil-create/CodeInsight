#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int pos[(1<<26)+20];
char s[maxn];
int dp[maxn];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	memset(pos,-1,sizeof(pos));
	for (int i=1;i<=len;i++)dp[i]=len;
	pos[0]=0;
	int x=0;
	for (int i=1;i<=len;i++){
		s[i]-='a';
		x^=(1<<s[i]);
		dp[i]=dp[i-1]+1;
		for (int j=0;j<26;j++){
			if (pos[x^(1<<j)]==-1)continue;
			dp[i]=min(dp[i],dp[pos[x^(1<<j)]]+1);
		}
		if (~pos[x])dp[i]=min(dp[i],dp[pos[x]]+1);
		if (pos[x]==-1)pos[x]=i;
		if (dp[i]<dp[pos[x]]) pos[x]=i;
	}
	printf("%d",dp[len]);
}