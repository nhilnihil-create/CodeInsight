#include <iostream>

int main() {

	int N, A, B;

	std::cin >> N >> A >> B;

	if (A * N >= B) {
		std::cout << B << std::endl;
	}
	else if (A * N < B) {
		std::cout << A * N << std::endl;
	}
}