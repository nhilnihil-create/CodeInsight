#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int a,b,c,p,F;
	scanf("%d %d %d",&a,&b,&c);
	
	p = (a + b + c)/ 2;
	F =sqrt(p * (p -a) * (p-b) * (p-c));
	
	printf("%d\n",F);
		
	return 0;
}