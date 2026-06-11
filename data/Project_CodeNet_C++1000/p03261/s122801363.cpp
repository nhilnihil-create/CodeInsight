#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	int N; std::cin >> N;
	std::vector<std::string> W(N);
	for (auto& r : W) std::cin >> r;
	char check;
	for (int i = 0; i < N; ++i) {
		if (i > 0 && check != W[i][0]) {
			std::cout << "No" << std::endl;
			return 0;
		}
		check = W[i].back();
		if (i > 0) {
			for (int j = i - 1; 0 <= j; --j)
				if (W[i] == W[j]) {
					std::cout << "No" << std::endl;
					return 0;
				}
		}
	}
	std::cout << "Yes" << std::endl;

	return 0;
}