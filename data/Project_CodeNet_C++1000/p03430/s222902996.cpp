#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[305][305][305],k;
char a[305];
inline int dfs(int l,int r,int x) {
	if(l>r) return 0;if(l==r) return 1;if(~dp[l][r][x]) return dp[l][r][x];
	int rt=max(dfs(l,r-1,x),dfs(l+1,r,x));
	if(a[l]==a[r]) rt=max(rt,2+dfs(l+1,r-1,x));
	if(x) rt=max(rt,2+dfs(l+1,r-1,x-1));
	dp[l][r][x]=rt;
	return rt;
}
int main()
{
	scanf("%s%d",a+1,&k);memset(dp,-1,sizeof(dp));
	printf("%d",dfs(1,strlen(a+1),k));
	return 0;
}