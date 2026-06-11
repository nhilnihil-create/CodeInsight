#include <stdio.h>
#include <iostream>

int main()
{
	int r, d, x;
	std::cin >> r;
	std::cin >> d;
	std::cin >> x;

	int output_num = 10;
	for (int i = 0; i < output_num; i++) {
		x = r * x - d;
		std::cout << x << std::endl;
	}

    return 0;
}