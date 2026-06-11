#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	int a, b, k;
	int m;
	std::cin >> a >> b >> k;
	int small = std::min(a, b);
	int large = std::max(a, b);
	std::vector<int> divs;
	for (int d = 1; d <= small; d++)
	{
		if (small % d == 0 && large % d == 0)
			divs.push_back(d);
	}
	std::cout << divs.at(divs.size() - k) << '\n';
	return 0;
}
