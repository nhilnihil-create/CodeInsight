#include "bits/stdc++.h"

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		int temp;
		std::cin >> temp;
		while ((temp & 1) == 0)
		{
			temp /= 2;
			a[i]++;
		}
	}
	std::cout << *std::min_element(a.begin(), a.end()) << '\n';
	return 0;
}