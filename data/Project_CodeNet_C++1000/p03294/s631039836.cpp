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
	/*std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());*/
	intt ans = 0;
	for (auto& r : a)
		ans += r - 1;
	std::cout << ans << std::endl;
}
