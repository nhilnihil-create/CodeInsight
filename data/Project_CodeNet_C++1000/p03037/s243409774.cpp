#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

int main() {
	int N, M; std::cin >> N >> M;
	std::vector<int> L(M);
	std::vector<int> R(M);
	for (int i = 0; i < M; ++i)
		std::cin >> L[i] >> R[i];
	std::sort(L.begin(), L.end());
	std::sort(R.begin(), R.end());
	if (R[0] - L[M - 1] < 0)
		std::cout << 0 << std::endl;
	else
		std::cout << R[0] - L[M - 1] + 1 << std::endl;

}