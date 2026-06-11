#include <bits/stdc++.h>
using namespace std;
string s;
int dp[305][305][305];
int solve(int l,int r,int k)
{
	if (k<0)
	return -1e9;
	if (r-l<1)
	return r-l+1;
	if (dp[l][r][k]!=-1)
	return dp[l][r][k];
	return dp[l][r][k]=max(max(solve(l+1,r,k),solve(l,r-1,k)),2+solve(l+1,r-1,k-(s[l]!=s[r])));
}
int main()
{
	int k;
	cin >> s >> k;
	memset(dp,-1,sizeof(dp));
	cout << solve(0,s.size()-1,k);
}