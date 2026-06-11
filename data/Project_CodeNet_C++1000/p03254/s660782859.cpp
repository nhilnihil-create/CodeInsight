#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N, x; std::cin >> N >> x;
	std::vector<int> a(N);
	for (auto& r : a) std::cin >> r;
	std::sort(a.begin(), a.end());
	int count = 0;
	for (auto& r : a) {
		x -= r;
		++count;
		if (x == 0) break;
		if (x < 0) {
			--count;
			break;
		}
	}
	if (x > 0) --count;
	std::cout << count << std::endl;

	return 0;
}