#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int solve(vector<int>& vec, int n, int k)
{
	int dp[n + 2][k + 2];
	for(int j = 0; j <= k; j++)dp[1][j] = (j > vec[1])?0:1;
	for(int i = 2; i <= n ;i++){
		for(int j = 0; j <= k; j++){
			if(j == 0)dp[i][j] = dp[i-1][j];
			else{
				dp[i][j] = (mod+dp[i][j-1]+dp[i-1][j] - ((j-vec[i]-1 >= 0)?dp[i-1][j-vec[i]-1]:0))%mod;
			}
		}
	}
	return dp[n][k];
}

signed main()
{
	int n, k;
	cin >> n >> k;
	vector<int> vec(n + 1);
	for(int i = 1; i <= n; i++)cin >> vec[i];
	cout << solve(vec, n, k);
}