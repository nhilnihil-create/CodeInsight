#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

int main() {
	int N; std::cin >> N;
	std::vector<int>A(N);
	std::vector<int>B(N);
	for (auto& r : A)
		std::cin >> r;
	for (auto& r : B)
		std::cin >> r;
	int max = 0;
	for (int p = 0; p < N; ++p) {
		int ans = 0;
		for (int i = 0; i <= p; ++i)
			ans += A[i];
		for (int j = p; j < N; ++j)
			ans += B[j];
		max = std::max(max, ans);
	}
	
		std::cout << max << std::endl;
}
