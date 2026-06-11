#include <stdio.h>
int main(){
	char string[20];
	scanf("%[^\n]", string);
	string[3] = '8';
	printf("%s", string);
	
	return 0;
}