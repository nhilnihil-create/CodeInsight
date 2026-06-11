#include <iostream>

int main() {
	int a, b, c, d; std::cin >> a >> b >> c >> d;
    std::cout << c - (d - b) << " " <<  d + (c - a) << " " << a - (d - b) << " " << b + (c - a) << std::endl;

	return 0;
}