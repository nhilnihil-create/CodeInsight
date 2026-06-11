#include <cstdio>

int main(void)
{
	int a, b, i;

	scanf("%d %d" ,&a, &b);

	if (a <= b)
		printf("%d" ,a);
	else
		printf("%d" ,a - 1);
	return 0;
}