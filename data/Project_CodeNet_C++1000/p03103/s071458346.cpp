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
	intt N, M; std::cin >> N >> M;
	std::vector<std::pair<intt, intt>> A(N);
	for (auto& r : A)
		std::cin >> r.first >> r.second;
	std::sort(A.begin(), A.end());
	intt ans = 0;
	for (auto& r : A) {
		ans += r.first * std::min(M, r.second);
		M -= std::min(M, r.second);
	}
	std::cout << ans << std::endl;

}
