#include <iostream>

char board[300][300];

int main() {
	int n;
	std::cin >> n;

	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
			std::cin >> board[y][x];

	auto check = [n](int k) -> bool {
		for (int y = 0; y < n; ++y)
			for (int x = 0; x < n; ++x)
				if (board[(k + y) % n][x] != board[(k + x) % n][y])
					return false;

		return true;
	};

	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (check(i))
			ans += n;

	std::cout << ans << std::endl;
}