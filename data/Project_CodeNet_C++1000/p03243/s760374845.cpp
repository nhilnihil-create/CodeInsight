#include<stdio.h>
int main()
{
	int n;
	int a,b,c;
	scanf("%d",&n);
	a=n/100;
	if(a*111>=n){
		printf("%d\n",a*111);
	}
	else{
		printf("%d\n",(a+1)*111);
	}
	return 0;
}