#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int a,b,F,G;
	scanf("%d %d",&a,&b);
	
	F=a*b;
	G= a*b*F;
	
	if(G%2 != 0)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
		
	return 0;
}