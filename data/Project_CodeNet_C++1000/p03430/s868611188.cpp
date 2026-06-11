#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,dp[305][305][305],vis[305][305];
string st;
void dfs(int l,int r)
{
	if (l>r) return;
	if (vis[l][r]) return;
	vis[l][r]=1;
	if (l==r)
	{
		fill(dp[l][r],dp[l][r]+m+1,1);
		return;
	}
	int i;
	dfs(l+1,r-1);
	dfs(l+1,r);
	dfs(l,r-1);
	for (i=0;i<=m;i++)
	{
		dp[l][r][i]=0;
		if (st[l]==st[r]) dp[l][r][i]=max(dp[l][r][i],dp[l+1][r-1][i]+2);
		else
		{
			if (i) dp[l][r][i]=max(dp[l][r][i],dp[l+1][r-1][i-1]+2);
			dp[l][r][i]=max(dp[l][r][i],dp[l+1][r][i]);
			dp[l][r][i]=max(dp[l][r][i],dp[l][r-1][i]);
		}
	}
}
int main()
{
	cin>>st>>m;
	st=" "+st;
	dfs(1,st.size()-1);
	cout<<dp[1][st.size()-1][m]<<endl;
	return 0;
}