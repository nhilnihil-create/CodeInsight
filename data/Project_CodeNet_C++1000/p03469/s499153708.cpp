#include<stdio.h>

int main(){
	char r[255];
	scanf("%[^\n]", r);
	r[0] = '2';
	r[1] = '0';
	r[2] = '1';
	r[3] = '8';
	printf("%s\n", r);
	return 0;
	
}