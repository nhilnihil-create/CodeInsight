#include <iostream>

int main()
{
	int X, Y;
	std::cin >> X >> Y;

	if (X <= 8 && Y <= 8)
	{
		std::cout << "Yay!";
	}
	else 
	{
		if (X <= Y)
		{
			if (4 * Y - 2 * X <= 16)
			{
				std::cout << "Yay!";
			}
			else
			{
				std::cout << ":(";
			}
		}
		else if (Y <= X)
		{
			if (4 * X - 2 * Y <= 16)
			{
				std::cout << "Yay!";
			}
			else
			{
				std::cout << ":(";
			}
		}
		else
		{
			std::cout << ":(";
		}
	}

	return 0;
}