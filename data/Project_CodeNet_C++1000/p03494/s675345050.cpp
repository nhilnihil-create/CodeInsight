#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	int min = 56562;
	int a;
	int j;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		for (j = 0; a % 2 == 0; j++) a /= 2;
		if (min > j) min = j;
	}
	
	std::cout << min << std::endl;
	
	return 0;
}
