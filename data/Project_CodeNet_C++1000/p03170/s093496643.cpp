#include<bits/stdc++.h>
using namespace std;
#define ll long long

string solve(vector<int>& v, int k)
{
	bool dp[k + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= k; i++)
	{
		for (int move : v)
		{
			if (move > i)
			{
				continue;
			}

			if (dp[i - move] == 0)//means for winning state
			{
				//cout << i - move << " " << dp[i - move] << " " << i << " " << dp[i] << " ";
				dp[i] = 1;
				//cout << dp[i] << endl;
			}
		}
		//cout << dp[i] << "\n";
	}
	return dp[k] ? "First" : "Second";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	std::vector<int> v(n );
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << solve(v, k);
}