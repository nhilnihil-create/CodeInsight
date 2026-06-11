#include <bits/stdc++.h> 
using namespace std; 
const int N = 24;
bool grid[24][24];
long long n , mod = 1e9 + 7 , dp[24][1<<22];
int solve(int m, int w)
{
	if (m == n)
	{
		if (w == 0)
			return 1;
		return 0;
	}
	if (dp[m][w] != -1)
		return dp[m][w];
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		bool okay = ((((1 << i) & w) == 0) ? 0 : 1);
		if (okay && grid[m][i])
			ans = (ans + solve(m + 1, (1 << i) ^ w)) % mod;
	}
	return dp[m][w] = ans;
}
int main(){
	cin>>n;
	for(int i=  0; i < n  ; i++)
		for(int j = 0; j < n ;j++)
			cin>>grid[i][j];
			
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,(1<<n)-1);
	return 0;
}  
