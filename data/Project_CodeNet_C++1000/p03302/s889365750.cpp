#include <stdio.h>
 
int main(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	int c=a+b,d=a*b;
	if(c==15){
		printf("+");
	}else if(d==15){
		printf("*");
	}else{
		printf("x");
	}
	printf("\n");
	return 0;
}