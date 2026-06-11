#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (auto &e : a) std::cin >> e;
	
	std::sort(a.begin(), a.end(), std::greater<int>{});
	int point = 0;
	for (int i = 0; i < n; i++) {
		point += i % 2 ? -a[i] : a[i];
	}
	
	std::cout << point << std::endl;
	
	return 0;
}
