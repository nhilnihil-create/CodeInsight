#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	int A, B, K; std::cin >> A >> B >> K;

	if (B - A + 1> K * 2) {
		for (int i = A; i < A + K; ++i)
			std::cout << i << std::endl;
		for (int i = B - K + 1; i <= B; ++i)
			std::cout << i << std::endl;
	}
	else
		for (int i = A; i <= B; ++i)
			std::cout << i << std::endl;

	return 0;
}