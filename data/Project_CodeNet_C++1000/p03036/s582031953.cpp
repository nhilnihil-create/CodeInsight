#include <iostream>

int main() {
	long long int r, d, x;
	std::cin >> r >> d >> x;

	for (int i = 0; i < 10; ++i) {
		std::cout << r * x - d << "\n";
		x = r * x - d;
	}
}