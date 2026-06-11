#include<stdio.h>

int main(){
	char s[11];
	scanf("%s", s);
	printf("2018/01/");
	printf("%c%c", s[8], s[9]); 
	return 0;
}