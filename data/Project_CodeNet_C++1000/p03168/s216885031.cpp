#include "bits/stdc++.h"

const int size = 3e3 + 5;

int n;

double dp[size]{ 1.0 };

int main()
{
	std::cout << std::fixed << std::setprecision(12);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		double x;
		std::cin >> x;
		for (int j = i; j > 0; --j)
		{
			dp[j] = dp[j] * (1.0 - x) + dp[j - 1] * x;
		}
		dp[0] = dp[0] * (1.0 - x);
	}
	double ans = 0.0;
	for (int i = 0; i <= n; ++i)
	{
		if (2 * i > n)
		{
			ans += dp[i];
		}
	}
	std::cout << ans << '\n';
	return 0;
}