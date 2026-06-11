#include <iostream>

int main() {

	int a, b;

	std::cin >> a >> b;

	if ((a * b) % 2 == 0) {
		std::cout << "Even" << std::endl;
	}
	else if ((a * b) % 2 == 1) {
		std::cout << "Odd" << std::endl;
	}
}