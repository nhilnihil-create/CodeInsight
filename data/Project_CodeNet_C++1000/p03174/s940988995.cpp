#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

//
int n;
vector<vector<int>>dp;
vector<vector<bool>>a;
//

int F(int idx, int mask)
{
	if (idx == n)
		return 1;
	int ans = 0;
	if (dp[idx][mask] != -1)
		return dp[idx][mask];
	for (int i = 0; i < n; i++)
	{
		if ((mask >> i) & 1 && a[idx][i])
			ans = (ans + 0ll + F(idx + 1, mask ^ (1 << i))) % MOD;
	}
	return (dp[idx][mask] = ans);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	a = vector<vector<bool>>(n, vector<bool>(n, 0));
	dp = vector<vector<int>>(n, vector<int>(1 << n, -1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x; cin >> x;
			a[i][j] = x;
		}
	}
	cout << F(0, (1 << n) - 1);

	return 0;
}