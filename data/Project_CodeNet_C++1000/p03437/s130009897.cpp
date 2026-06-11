#include <iostream>
#include <stdio.h>
int main()
{
	int x, y,N;
	std::cin >> x >> y;
	
	if (x % y == 0) {
		std::cout << "-1";
		return 0;
	}
	for (int i = 1;i<100000000;i++)
	{
		N = x * i;
		if (N % y != 0) {
			std::cout << N;
			return 0;
		}
	}
    std::cout << "-1";
}