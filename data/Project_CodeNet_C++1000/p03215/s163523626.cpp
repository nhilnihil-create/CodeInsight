#include <bits/stdc++.h>

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	std::vector<int> a(N);
	for (auto& e: a) scanf("%d", &e);
	std::vector<int64_t> sum;
	sum.reserve(N * (N + 1) / 2);
	for (int i{}; i < N; i++)
	{
		int64_t tmp{};
		for (int j{i}; j < N; j++)
		{
			tmp += a[j];
			sum.push_back(tmp);
		}
	}
	int64_t ans{};
	for (int digit{40}; digit >= 0; digit--)
	{
		std::sort(sum.rbegin(), sum.rend());
		int left{-1}, right{(int)sum.size()};
		while (right - left > 1)
		{
			int mid{(right + left) / 2};
			if (sum[mid] >= (1ll << digit)) left = mid;
			else right = mid;
		}
		if (right >= K)
		{
			while (sum.back() < (1ll << digit)) sum.pop_back();
			ans += (1ll << digit);
		}
		for (auto& e: sum) e = e & (-1 ^ (1ll << digit));
	}
	printf("%lld\n", ans);

	return 0;
}