#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main() {
	long long A, B, C, K; std::cin >> A >> B >> C >> K;
	if (std::abs(A - B) > 1000000000000000000) {
		std::cout << "Unfair" << std::endl;
		return 0;
	}
	if(K % 2 == 1)
		std::cout << B - A << std::endl;
	else
		std::cout << A - B << std::endl;


	return 0;
}