#include<stdio.h>
#include<math.h>
int main()
{
	int x,i,j,a,max,s1,s2,t;
	scanf("%d", &x);
	max=10000;
	if(x==1)
	{
		printf("1\n");
		return 0;
	}
	for(i=2; i<=sqrt(x); i++)
	{
		t=1;
		while(t<=x)
			t*=i;
		t/=i;
		if(x-t<max)
			max=x-t;
	}
	printf("%d\n",x-max);
	return 0;
}