#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int N; std::cin >> N;
	int ans{ 0 };
	for (auto i{ 1 }; i <= N; ++i) {
		if (i % 2 == 1) {
			int count{ 0 };
			for (int j{ 1 }; j <= i; ++j) {
				if (i % j == 0) ++count;
			}
			if (count == 8) ++ans;
		}
	}
	std::cout << ans << std::endl;

	return 0;
}
