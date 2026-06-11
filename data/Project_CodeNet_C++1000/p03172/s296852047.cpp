#include "bits/stdc++.h"

using ll = long long;

const int MOD = 1000000007;

const int size = 1003;

const int numberOfCandies = 100005;

const int numberOfChildren = 102;

void Break()
{
#if _MSC_VER
	static int x = 0;
	++x;
	switch (x)
	{
		__debugbreak();
	}
#endif
}

int dp[numberOfCandies];

int main()
{
#if _MSC_VER
	freopen("input.txt", "r", stdin);
#endif
	std::vector<int> children(numberOfChildren);
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> children[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		std::vector<int> sum(k + 1);
		sum[0] = dp[0];
		for (int j = 1; j <= k; ++j)
		{
			sum[j] = (dp[j] + sum[j - 1]) % MOD;
		}
		for (int j = 0; j <= k; ++j)
		{
			if (j > children[i])
			{
				dp[j] = (sum[j] - sum[j - children[i] - 1] + MOD) % MOD;
			}
			else
			{
				dp[j] = sum[j];
			}
		}
	}
	std::cout << dp[k] << '\n';
	return 0;
}