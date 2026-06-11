#include<stdio.h>
int main()
{
	int r;
	scanf("%d",&r);
	if(1200>r){
		printf("ABC\n");
	}
	else if(2800>r){
		printf("ARC\n");
	}
	else{
		printf("AGC\n");
	}
	return 0;
}