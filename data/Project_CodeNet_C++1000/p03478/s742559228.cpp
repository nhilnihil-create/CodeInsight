#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int digit_sum(int n) {
	if (n < 10)  return n;
	return digit_sum(n / 10) + n % 10;
}

int main() {
	int N, A, B; std::cin >> N >> A >> B;
	long long ans = 0;
	for (int i = 1; i <= N; ++i) {
		int all = digit_sum(i);
		if (A <= all && all <= B) ans += i;
	}
	std::cout << ans << std::endl;

	return 0;
}