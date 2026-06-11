#include <bits/stdc++.h>

int main()
{
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	std::vector<std::pair<int, int>> a_sorted(n);
	std::vector<int> a(n);
	for (int i{}; i < n; i++)
	{
		scanf("%d", &a_sorted[i].first);
		a[i] = a_sorted[i].first;
		a_sorted[i].second = i;
	}
	std::sort(a_sorted.begin(), a_sorted.end());
	int min{a_sorted[q - 1].first - a_sorted[0].first};
	std::vector<bool> used(n + 1);
	used[a_sorted[0].second] = used[n] = true;
	for (int i{1}; i < n; i++)
	{
		if (a_sorted[i].first == a_sorted[i - 1].first)
		{
			used[a_sorted[i].second] = true;
			continue;
		}
		int left{};
		std::vector<int> can_use;
		for (int j{}; j <= n; j++)
		{
			if (!used[j]) continue;
			if (j - left < k)
			{
				left = j + 1;
				continue;
			}
			std::vector<int> tmp;
			for (int l{left}; l < j; l++)
				tmp.push_back(a[l]);
			std::sort(tmp.begin(), tmp.end());
			for (int l{}; l < j - left - (k - 1); l++)
				can_use.push_back(tmp[l]);
			left = j + 1;
		}
		if (can_use.size() < q)
			break;
		std::sort(can_use.begin(), can_use.end());
		min = std::min(min, can_use[q - 1] - can_use[0]);
		used[a_sorted[i].second] = true;
	}
	printf("%d\n", min);
	return 0;
}