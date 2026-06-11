#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

int main()
{
	int n, x;
	std::cin >> n >> x;
	std::vector<int> a(n);
	for (auto &e : a) std::cin >> e;
	
	if (std::accumulate(a.begin(), a.end(), 0ll) == x) {
		std::cout << n << std::endl;
		return 0;
	}
	std::sort(a.begin(), a.end());
	int i;
	for (i = 0; i < n; i++) {
		x -= a[i];
		if (x < 0) break;
	}
	if (i == n) i--;
	
	std::cout << i << std::endl;
	
	return 0;
}
