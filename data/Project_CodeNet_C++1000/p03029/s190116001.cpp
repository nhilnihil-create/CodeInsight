#include<stdio.h>

int main(){
	int a, p;
	scanf("%d %d", &a, &p);
	p+=(a*3);
	if(p<2){
		printf("0\n");
	}
	else{
		printf("%d\n", p/2);
	}
	return 0;
}