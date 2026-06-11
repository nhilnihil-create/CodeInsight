#include "bits/stdc++.h"

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	int min = std::numeric_limits<int>::max();
	for (int i = 0; i < n && i + k - 1 < n; ++i)
	{
		min = std::min(min, v[i + k - 1] - v[i]);
	}
	std::cout << min << '\n';
	return 0;
}