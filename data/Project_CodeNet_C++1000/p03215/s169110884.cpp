#include <bits/stdc++.h>

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	std::vector<int64_t> a(N);
	for (auto& e: a) scanf("%lld", &e);
	std::vector<int64_t> beauty;
	beauty.reserve(N * N);
	for (int i{}; i < N; i++)
	{
		int64_t sum{};
		for (int j{i}; j < N; j++)
		{
			sum += a[j];
			beauty.push_back(sum);
		}
	}
	
	int64_t ans{};
	for (int i{40}; i >= 0; i--)
	{
		std::sort(beauty.rbegin(), beauty.rend());
		if (beauty[K - 1] >> i & 1)
		{
			ans += 1ll << i;
			while (~beauty.back() >> i & 1) beauty.pop_back();
		}
		for (auto& e: beauty)
			e &= -1 ^ (1ll << i);
	}
	printf("%lld\n", ans);

	return 0;
}