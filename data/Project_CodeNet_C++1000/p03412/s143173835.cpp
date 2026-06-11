#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <array>
#include <cstddef>

using std::size_t;

constexpr size_t SIZE = 200000;

int n, ans;
std::array<int, SIZE> a, b;

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) std::cin >> a[i];
	for (int i = 0; i < n; i++) std::cin >> b[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans ^= (a[i] + b[j]);
		}
	}
	std::cout << ans << '\n';
	return 0;
}