#include<stdio.h>
int main()
{
	int count=5,max=0,sum=0,d,temp;
	while(count--)
	{
		scanf("%d", &d);
		temp = ((d+10-1)/10)*10;
		sum+=temp;
		if(temp-d>max) max = temp-d;
	}
	sum-=max;
	printf("%d\n", sum);
	return 0;
}