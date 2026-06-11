#include<stdio.h>

int main()
{
	int n, m, mult, sum;
	
	scanf("%d %d", &n, &m);
	
	mult = n * 3;
	sum = m + mult;
	
	printf("%d\n", sum/2);
}