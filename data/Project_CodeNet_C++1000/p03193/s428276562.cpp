#include <iostream>

int main() {
	unsigned long n, h, w, a, b;
	std::cin >> n >> h >> w;

	unsigned long res = 0;
	for (unsigned long i = 0; i < n; ++i) {
		std::cin >> a >> b;
		if (a >= h && b >= w) {
			res++;
		}
	}
	std::cout << res << std::endl;
}