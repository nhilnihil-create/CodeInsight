#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=(int)2e5+5;
char str[MAXN];
int mark[MAXN],dp[(1<<26)+10];
int main()
{
	int n;
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=(1<<26);i++)dp[i]=(int)1e9;
	for(int i=1;i<=n;i++){
		mark[i]=(mark[i-1]^(1<<(str[i]-'a')));
		for(int j=0;j<26;j++){
			dp[mark[i]]=min(dp[mark[i]^(1<<j)]+1,dp[mark[i]]);
		}
	}
	dp[0]=1;
	printf("%d\n",dp[mark[n]]);
	return 0;
}