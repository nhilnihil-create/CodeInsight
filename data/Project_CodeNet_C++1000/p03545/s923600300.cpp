#include <iostream>

int dfs(int index, int total, int op, int* A)
{
	int ret = op;
	if (index == 4)
	{
		if (total == 7)
		{
			ret = op & 0x7;
		}
	}
	else
	{
		ret = dfs(index + 1, total + A[index], op | (0x1 << (index - 1)), A);
		if (static_cast<bool>(ret & 0x8))
		{
			ret = dfs(index + 1, total - A[index], op, A);
		}
	}
	return ret;
}

int main()
{
	int D[4] = { 1000, 100, 10, 1 };
	int A[4];
	char C[2] = { '-', '+' };
	int N;
	std::cin >> N;
	for (int i = 0; i < 4; ++i)
	{
		A[i] = N / D[i];
		N %= D[i];
	}

	char ANS[8];
	int ret = dfs(1, A[0], 0x8, A);
	ANS[0] = '0' + A[0];
	for (int i = 0; i < 3; ++i)
	{
		int opi = (ret >> i) & 0x1;
		ANS[i * 2 + 1] = C[opi];
		ANS[i * 2 + 2] = '0' + A[i + 1];
	}

	ANS[7] = 0;

	std::cout << ANS << "=7" << std::endl;

	return 0;
}
