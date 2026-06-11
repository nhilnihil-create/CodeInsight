#include <bits/stdc++.h>

int main()
{
	int N;
	std::string S;
	std::cin >> N >> S;
	int limit{1 << N};
	std::vector<std::pair<std::string, std::string>> former(limit);
	for (int i{}; i < limit; i++)
	{
		for (int j{}; j < N; j++)
			if (i >> j & 1)
				former[i].first += S[j];
		for (int j{N - 1}; j >= 0; j--)
			if (~i >> j & 1)
				former[i].second += S[j];
	}
	std::sort(former.begin(), former.end());

	long long count{};
	for (int i{}; i < limit; i++)
	{
		std::pair<std::string, std::string> tmp;
		for (int j{}; j < N; j++)
			if (i >> j & 1)
				tmp.first += S[2 * N - 1 - j];
		for (int j{N - 1}; j >= 0; j--)
			if (~i >> j & 1)
				tmp.second += S[2 * N - 1 - j];
		count += std::upper_bound(former.begin(), former.end(), tmp) - std::lower_bound(former.begin(), former.end(), tmp);
	}
	printf("%lld\n", count);

	return 0;
}