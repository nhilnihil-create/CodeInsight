#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <random>
#include <iomanip>
#include <iterator>
#include <utility>

typedef long long ll;
typedef unsigned long long ull;

int main() {
	int n, k;
	std::vector<int> x;
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		x.push_back(a);
	}
	int ans = 1000000000;
	int temp = 0;
	for (int i = 0; i < n - k + 1; ++i) {
		if (std::abs(x[i + k - 1] - x[i] + std::abs(x[i])) < ans || std::abs(x[i + k - 1] - x[i] + std::abs(x[i + k - 1])) < ans) {
			ans = std::min(std::abs(x[i + k - 1] - x[i] + std::abs(x[i])), std::abs(x[i + k - 1] - x[i] + std::abs(x[i + k - 1])));
		}
	}
	std::cout << ans << std::endl;
}