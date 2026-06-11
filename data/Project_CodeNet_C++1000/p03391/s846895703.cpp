#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
	std::size_t n;
	std::cin >> n;
	std::vector<long long> a(n), b(n);
	for (std::size_t i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
	}
	
	if (a == b) {
		std::cout << 0 << '\n';
	} else {
		long long sum = std::accumulate(a.begin(), a.end(), 0LL);
		long long min = (1LL << 60);
		for (std::size_t i = 0; i < n; i++) {
			if (a[i] > b[i]) min = std::min(min, b[i]);
		}
		std::cout << sum - min << '\n';
	}
	
	return 0;
}