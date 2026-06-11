#include "bits/stdc++.h"

const int size = 22;

const int MOD = 1e9 + 7;

int n;

int a[size][size];
int dp[size][1 << 21];

int Solve(int ndx, int visited)
{
	if (ndx >= n)
	{
		return 1;
	}
	if (dp[ndx][visited] != -1)
	{
		return dp[ndx][visited];
	}
	int ans = 0;
	for (int i = 0; i < 21; ++i)
	{
		if (!(visited & (1 << i)) && a[ndx][i] == 1)
		{
			ans = (ans + Solve(ndx + 1, visited | (1 << i))) % MOD;
		}
	}
	return dp[ndx][visited] = ans;
}

int main()
{
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 1 << 21; ++j)
		{
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cin >> a[i][j];
		}
	}
	std::cout << Solve(0, 0) << '\n';
	return 0;
}