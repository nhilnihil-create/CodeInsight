#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int A, B, K; std::cin >> A >> B >> K;
	int min = std::min(A, B);
	std::vector<int> X;
	for (auto i{ 1 }; i <= min; ++i) {
		if (A % i == 0 && B % i == 0)
			X.push_back(i);
	}
	std::reverse(X.begin(), X.end());
	std::cout << X.at(K - 1) << std::endl;

	return 0;
}
