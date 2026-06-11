#include<bits/stdc++.h>
using namespace std;
#define inf 0x7fffffff
#define X first
#define Y second
#define N 120010
typedef long long ll;
int dp[305][305][305];
char s[305];

int dfs(int l,int r,int k){
	if(l>r)return 0;
	if(l==r)return 1;

	if(dp[l][r][k]!=-1)return dp[l][r][k];
	dp[l][r][k]=max(dfs(l+1,r,k),dfs(l,r-1,k));
	if(s[l]==s[r])dp[l][r][k]=max(dfs(l+1,r-1,k)+2,dp[l][r][k]);
	else if(k>=1) dp[l][r][k]=max(dfs(l+1,r-1,k-1)+2,dp[l][r][k]);
	return dp[l][r][k];
}
int main()  {
	memset(dp,-1,sizeof(dp));
	int k;
	scanf("%s",&s);
	scanf("%d",&k);
	printf("%d\n",dfs(0,strlen(s)-1,k));
     return 0;
}
