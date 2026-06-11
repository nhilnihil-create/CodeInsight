#include <iostream>

int main()
{
	int n, d, x;
	std::cin >> n >> d >> x;
	
	d--;
	x += n;
	int a;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		x += d / a;
	}
	
	std::cout << x << std::endl;
	
	return 0;
}
