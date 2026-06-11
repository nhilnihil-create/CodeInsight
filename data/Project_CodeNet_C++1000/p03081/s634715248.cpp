#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
	int n, q;
	std::string s;
	std::cin >> n >> q >> s;

	std::vector<std::pair<char, char>> query(q);
	for (auto&& e : query)
		std::cin >> e.first >> e.second;

	auto simulatePos = [&](int idx) -> int {
		for (auto&& e : query) {
			if (e.first != s[idx])
				continue;

			if (e.second == 'L')
				--idx;
			else
				++idx;

			if (idx == -1 || idx == n)
				return idx;
		}

		return idx;
	};
	auto countLeftFall = [&]() {
		int l = 0, r = n;

		while (r - l > 1) {
			int mid = (l + r) / 2;

			if (simulatePos(mid) == -1)
				l = mid;
			else
				r = mid;
		}

		if (l == 0)
			return static_cast<int>(simulatePos(0) == -1);
		else
			return l + 1;
	};
	auto countRightFall = [&]() {
		int l = -1, r = n - 1;

		while (r - l > 1) {
			int mid = (l + r) / 2;

			if (simulatePos(mid) == n)
				r = mid;
			else
				l = mid;
		}

		if (r == n - 1)
			return static_cast<int>(simulatePos(n - 1) == n);
		else
			return n - r;
	};
	
	int ans = n;

	ans -= countLeftFall();
	ans -= countRightFall();

	std::cout << ans << std::endl;
}