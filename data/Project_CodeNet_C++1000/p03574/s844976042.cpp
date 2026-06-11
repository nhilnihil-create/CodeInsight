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
	std::vector<std::vector<char>> S(H + 2, std::vector<char>(W + 2));
	std::vector<std::vector<int>> SS(H + 2, std::vector<int>(W + 2));
	for (int i = 1; i < H + 1; ++i)
		for (int j = 1; j < W + 1; ++j)
			std::cin >> S[i][j];
	for (int i = 1; i < H + 1; ++i)
		for (int j = 1; j < W + 1; ++j)
			if (S[i][j] == '.') {
				int a = 0;
				if (S[i + 1][j] == '#')
					++a;
				if (S[i - 1][j] == '#')
					++a;

				if (S[i - 1][j - 1] == '#')
					++a;
				if (S[i][j - 1] == '#')
					++a;
				if (S[i + 1][j - 1] == '#')
					++a;

				if (S[i - 1][j + 1] == '#')
					++a;
				if (S[i][j + 1] == '#')
					++a;
				if (S[i + 1][j + 1] == '#')
					++a;
				SS[i][j] = a;
			}
	for (int i = 1; i < H + 1; ++i) {
		for (int j = 1; j < W + 1; ++j) {
			if (S[i][j] == '#') {
				std::cout << S[i][j];
			}
			else
				std::cout << SS[i][j];
		}
		std::cout << std::endl;
	}
}