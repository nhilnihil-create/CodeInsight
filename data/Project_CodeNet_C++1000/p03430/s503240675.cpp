#include<bits/stdc++.h>
using namespace std;
int dp[310][310][310],n;
char s[310];
int dfs(int l,int r,int k){
	if(k<0)return -1000000007;
	if(l>r)return 0;
	else if(l==r)return 1;
	if(~dp[l][r][k])return dp[l][r][k];
	dp[l][r][k]=max(dfs(l+1,r,k),dfs(l,r-1,k));
	dp[l][r][k]=max(dp[l][r][k],dfs(l+1,r-1,k-(s[l]!=s[r]))+2);
//	printf("{%d,%d,%d,%d}",l,r,k,dp[l][r][k]);
	return dp[l][r][k];
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%s%d",s+1,&n);
	printf("%d\n",dfs(1,strlen(s+1),n));
}