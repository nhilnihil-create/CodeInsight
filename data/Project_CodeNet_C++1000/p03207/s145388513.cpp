#include<stdio.h>

int main()
{
	int i, sum,tc, num[100000],save, j, min;
	
	scanf("%d", &tc);
	for(i =0; i<tc; i++)
		scanf("%d", &num[i]);
	min = num[0];
	for(i =0; i < tc; i++)
	{
		if(num[i] >= min)
		{
			min = num[i];
		
			save = i;
		}
	}
	sum = 0;
	for(i = 0; i<tc; i++)
	{
		if(i==save)
			sum = sum + num[i] / 2;
		else 
			sum += num[i];
	}
	printf("%d\n", sum);
	return 0;
}