#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;

	int cnt[100010];


	int min = 1e6;
	int max = 0;
	for (int i = 0; i < m; ++i) {
		int l, r;
		std::cin >> l >> r;
		min = std::min(min, r);
		max = std::max(max, l);
	}

	std::cout << std::max(0, min - max + 1);
}