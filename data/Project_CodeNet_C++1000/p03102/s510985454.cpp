#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N, M, C; std::cin >> N >> M >> C;
	int count{ 0 };
	std::vector<int> B(M);
	for (auto& r : B) std::cin >> r;
	std::vector<std::vector<int>> A(N, std::vector<int>(M));
	for (int i = 0; i < N; ++i) {
		int sum = 0;
		for (int j = 0; j < M; ++j) {
			std::cin >> A[i][j];
			sum += A[i][j] * B[j];
		}
		if (sum + C > 0)
			++count;
	}
	std::cout << count << std::endl;

	return 0;
}