#include <bits/stdc++.h>

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<long long> sum(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &sum[i]);
		if (i) sum[i] += sum[i - 1];
	}
	long long min{(long long)1 << 60};
	int p_i{0}, r_i{2};
	for (int left{1}; left < n - 2; left++)
	{
		if (r_i == left) r_i++;
		for (; p_i < left - 1 && std::abs(sum[left] - 2 * sum[p_i]) > std::abs(sum[left] - 2 * sum[p_i + 1]); p_i++);
		for (; r_i < n - 2 && std::abs(sum[n - 1] + sum[left] - 2 * sum[r_i]) > std::abs(sum[n - 1] + sum[left] - 2 * sum[r_i + 1]); r_i++);
		long long pqrs[4]{sum[p_i], sum[left] - sum[p_i], sum[r_i] - sum[left], sum[n - 1] - sum[r_i]};
		min = std::min(min, *std::max_element(pqrs, pqrs + 4) - *std::min_element(pqrs, pqrs + 4));
	}
	printf("%lld\n", min);
	return 0;
}