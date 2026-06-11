#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf (int)1<<60
int dp[(1<<16)];
int sum[(1<<16)];

int calculate(vector<vector<int> >& score, int mask)
{
	int ans = 0;
	for(int i = 0; i < 17; i++)
	{
		for(int j = i + 1; j < 17; j++)
		{
			if(((mask & (1<<i))!=0) && ((mask & (1<<j))!=0))
				ans += score[i][j];	
		}
	}
	return ans;
}
void prepareSum(vector<vector<int> >&score, int n)
{
	for(int i = 1; i < (1 << n); i++)
		dp[i] = inf;
	//summing up the values for each and every subset
	for(int submask = 1; submask < (1<<n); submask++)
		sum[submask] = calculate(score, submask);
}

int solve(vector<vector<int> >&score, int mask)
{
	if(mask == 0)return 0;
	if(dp[mask]!=inf)
		return dp[mask];
	int ans = 0;
	for(int submask = mask; submask!=0; submask = (submask-1)&mask)//generating all the subsets of the mask
		ans = max(ans ,sum[submask]+solve(score,mask^submask));//xoring the submask and mask
	return dp[mask] = ans;
}
signed main()
{
	int n;
	cin >> n;
	vector<vector<int> >score(n, vector<int>(n));
	//memset(dp, inf, sizeof dp);
	for(int  i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> score[i][j];
	prepareSum(score, n);
	cout << solve(score, (1<<n)-1);
}