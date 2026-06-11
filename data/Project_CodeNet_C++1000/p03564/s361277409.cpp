#include<stdio.h>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	int i, res = 1;
	for (i = 1; i <= n; i++)
	{
		if (res + k <= res * 2)
		{
			res += k;
		}
		
		else
		{
			res *= 2;
		}
	}
	
	printf("%d\n", res);
	
	return 0;
}