#include<stdio.h>
int main(void)
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	if(a>=13){
		printf("%d\n",b);
	}
	else if(a<=5){
		printf("0\n");
	}
	else{
		b = b/2;
		printf("%d\n",b);
	}
	return 0;
}