#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int a, b, c;

	std::cin >> a >> b >> c;

	if (a != b || b != c || a != c) {
		std::cout << "No" << std::endl;
		return 0;
	}

	std::cout << "Yes" << std::endl;
}