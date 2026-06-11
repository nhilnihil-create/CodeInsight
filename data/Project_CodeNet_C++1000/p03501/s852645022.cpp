

#include <iostream>

int main() {
	int n, a, b;
	std::cin >> n >> a >> b;
	if (n * a < b) {
		std::cout << n * a << std::endl;
	} else {
		std::cout << b << std::endl;
	}
}

