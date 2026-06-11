#include <iostream>

int main()
{
	int SIZE;

	std::cin >> SIZE;

	int* array = (int*)malloc(sizeof(int) * SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		std::cin >> array[i];
	}

	int t = 0;
	while (true)
	{
		//2で割れるかの判定
		bool isWaru = false;

		bool flug = false;
		for (int i = 0; i < SIZE; i++)
		{
			if (array[i] % 2 == 0)
			{
				if (!flug)
				{
					array[i] = array[i] * 0.5;
					isWaru = true;
					flug = true;
				}
				else
				{
					array[i] = array[i] * 3;
				}
			}
			else
			{
				array[i] = array[i] * 3;
			}
		}
		if (!isWaru) break;
		
		t++;
	}
	std::cout << t;

	return 0;
}