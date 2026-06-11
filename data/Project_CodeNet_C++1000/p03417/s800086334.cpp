#include <iostream>

int main()
{
	long long n, m;
	std::cin >> n >> m;
	if (n == 1 && m == 1)
	{
		std::cout << 1;
		return 0;
	}
	if (n == 1 || m == 1)
	{
		if (n == 1)
		{
			std::cout << m - 2;
			return 0;
		}
		if (m == 1) 
		{
			std::cout << n - 2;
			return 0;
		}

	}
	std::cout << (n - 2) * (m - 2);
	return 0;
}