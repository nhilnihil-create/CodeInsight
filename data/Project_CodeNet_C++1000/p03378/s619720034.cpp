#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N, M, X; std::cin >> N >> M >> X;
	std::vector<int> A(M);
	int countL = 0; int countR = 0;
	for (auto& r : A) {
		std::cin >> r;
		if (r > X)
			++countL;
		else
			++countR;
	}
	std::cout << std::min(countL, countR);

	return 0;
}