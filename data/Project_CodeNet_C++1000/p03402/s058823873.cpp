#include <iostream>

#define LENG 100

char map[100][100];

int main()
{
	for (int i = 0; i < LENG; i++)
		for (int j = 0; j < LENG; j++)
		{
			if (i < 50)
			{
				map[i][j] = '.';
			}
			else
			{
				map[i][j] = '#';
			}
		}
	int n, m;
	std::cin >> n >> m;

	int black_i = 51, black_j = 0;
	int white_i = 0, white_j = 0;

	while (n > 1)
	{
		if (black_j == 100)
		{
			black_i += 2;
			black_j = 0;
		}
		if (black_i % 2 == 0)
		{
			if (black_j % 2 == 0)
			{
				map[black_i][black_j] = '.';
				black_j++;
				n--;
			}
			else
			{
				black_j++;
			}
		}
		else
		{
			if (black_j % 2 == 0)
			{
				black_j++;
			}
			else
			{
				map[black_i][black_j] = '.';
				black_j++;
				n--;
			}
		}
	}

	while (m > 1)
	{
		if (white_j== 100)
		{
			white_i += 2;
			white_j = 0;
		}
		if (white_i % 2 == 0)
		{
			if (white_j% 2 == 0)
			{
				map[white_i][white_j] = '#';
				white_j++;
				m--;
			}
			else
			{
				white_j++;
			}
		}
		else
		{
			if (white_j % 2 == 0)
			{
				white_j++;
			}
			else
			{
				map[white_i][white_j] = '.';
				white_j++;
				m--;
			}
		}
	}

	std::cout << "100 100" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			std::cout << map[i][j];
			if (j == 99)
				std::cout << std::endl;
		}
	}
	return 0;
}