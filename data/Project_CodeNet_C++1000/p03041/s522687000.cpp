#include<stdio.h>

int main(){
	int a,b;
	scanf("%d %d", &a,&b);
	char string[a+1]="";
	scanf("%s", &string);
	string [b-1]+= 32;
	printf("%s", string);
	return 0;
}