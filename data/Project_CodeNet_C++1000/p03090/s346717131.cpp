#include <stdio.h>

int main(void)
{
	int n, i, j;

	scanf("%d" ,&n);

	printf("%d\n" ,n * (n - 1) / 2 - n / 2);
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
			if (i + j != n + (1 - n % 2))
				printf("%d %d\n" ,i, j);
	return 0;
}