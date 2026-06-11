#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int h, w;
	std::cin >> h >> w;

	std::vector<std::vector<int>>c(10, std::vector<int>(10));
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			std::cin >> c.at(i).at(j);

	std::vector<std::vector<int>>a(h, std::vector<int>(w));
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			std::cin >> a.at(i).at(j);

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				c.at(j).at(k) = std::min(c.at(j).at(k), c.at(j).at(i) + c.at(i).at(k));

	long long ans = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (a.at(i).at(j) != -1)
				ans += c.at(a.at(i).at(j)).at(1);

	std::cout << ans;
}