#include<stdio.h>
#include<string.h>
#include<math.h>
//言語は「C++14(GCC 5.4.1)」
//AtCoder Beginner Contest 63-A

int main(void)
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	if (a + b == 15)
		printf("+");
	else if (a*b == 15)
		printf("*");
	else
		printf("x");
	return 0;
}