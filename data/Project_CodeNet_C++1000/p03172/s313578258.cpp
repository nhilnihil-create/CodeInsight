#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr(a,b) for(int i=a;i<b;i++)
#define prDouble(x) cout<<fixed<<setprecison(18)<<x
#define mod 1000000007

int solve(std::vector<int>& v, int n, int k)
{
	ll dp[n + 2][k + 2];


	//base case
	//number of candies greater then maxm
	for (int j = 0; j <= k; j++)
		dp[1][j] = (j > v[1]) ? 0 : 1;

	//considering first i children distribute j candies
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j == 0)//give zero candies as we have zero candies
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = (mod +  dp[i][j - 1] + dp[i - 1][j] - ((j - v[i] - 1 >= 0) ? dp[i - 1][j - v[i] - 1] : 0)) % mod;
		}
	}
	return dp[n][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	std::vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	cout << solve(v, n, k);
}