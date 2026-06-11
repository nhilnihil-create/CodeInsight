#include <cstdio>

bool is_prime(int x)
{
	int i;

	for (i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main(void)
{
	int n, i;

	scanf("%d" ,&n);

	int cnt = 0;
	for (i = 11; ; i += 10)
	{
		if (is_prime(i))
		{
			printf("%d " ,i);
			++cnt;
		}

		if (cnt >= n)
			break;
	}
	return 0;
}