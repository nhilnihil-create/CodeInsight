#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main() {
	intt N; std::cin >> N;
	std::vector<intt> a(N);
	for (auto& r : a) std::cin >> r;
	intt count = 1;
	for (auto& r : a) {
		intt t = 0;
		if ((r - 1) % 2 == 1)
			++t;
		if (r % 2 == 1)
			++t;
		if ((r + 1) % 2 == 1)
			++t;
		count *= t;
	}
	std::cout << std::pow(3, N) - count << std::endl;

}
