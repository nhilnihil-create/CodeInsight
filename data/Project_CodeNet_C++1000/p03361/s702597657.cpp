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
	intt H, W; std::cin >> H >> W;
	std::vector<std::vector<char>> M(H+2, std::vector<char>(W+2));
	for (int i = 1; i < H+1; ++i)
		for (int j = 1; j < W+1; ++j)
			std::cin >> M[i][j];
	for (int i = 1; i < H + 1; ++i) {
		for (int j = 1; j < W + 1; ++j) {
			if (M[i][j] == '#') {
				if (M[i - 1][j] != '#' && M[i][j - 1] != '#' && M[i + 1][j] != '#' && M[i][j + 1] != '#') {
					std::cout << "No" << std::endl;
					return 0;
				}
			}
		}
	}
	std::cout << "Yes" << std::endl;

	return 0;
}