#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

long long hundred(long long& n) {
	int count = 0;
	while (n % 100 == 0) {
		n /= 100;
		++count;
	}
	return count;
}

int main() {
	long long d, N; std::cin >> d >> N;
    if (N == 100) N = 101;
    if (d == 0) std::cout << N << std::endl;
    else if (d == 1) std::cout << 100 * N << std::endl;
    else if (d == 2) std::cout << 10000 * N << std::endl;
}
