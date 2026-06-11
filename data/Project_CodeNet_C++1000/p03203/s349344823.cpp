#include <bits/stdc++.h>

int solve();

int main()
{
	printf("%d\n", solve());

	return 0;
}

int solve()
{
	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);
	std::vector<std::pair<int, int>> yx;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		yx.push_back({y, x});
	}
	std::sort(yx.begin(), yx.end(),
		[](const auto& a, const auto& b)
		{
			if (a.first != b.first) return a.first < b.first;
			else return a.second < b.second;
		}
	);
	
	int min_x{1 << 30}, shift{};
	for (int i = 0; i < n; i++)
	{
		if (yx[i].first + shift < yx[i].second)
			min_x = std::min(min_x, yx[i].second);
		else if (yx[i].first + shift == yx[i].second)
			shift++;
	}
	if (min_x == 1 << 30) return h;
	return min_x - 1;
}
