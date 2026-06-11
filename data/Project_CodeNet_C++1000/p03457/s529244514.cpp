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
	intt N; std::cin >> N;
	std::vector<intt> t(N);
	std::vector<intt> x(N);
	std::vector<intt> y(N);
	for (intt i = 0; i < N; ++i)
		std::cin >> t[i] >> x[i] >> y[i];
	intt X = 0;
	intt Y = 0;
	intt T = 0;
	bool flag = true;
	for (intt i = 0; i < N; ++i) {
		X = std::abs(X - x[i]);
		Y = std::abs(Y - y[i]);
		T = t[i] - T;
		if (X + Y > T || (X + Y) % 2 != T % 2)
			flag = false;
	}
	if (flag == true)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	return 0;
}