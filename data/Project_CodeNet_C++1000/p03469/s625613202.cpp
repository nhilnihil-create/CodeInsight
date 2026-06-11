#include <stdio.h>

int main(){
	char input[10];
	scanf("%s",&input);
	input[3]='8';
	printf("%s\n", input);	
	
	return 0;
}