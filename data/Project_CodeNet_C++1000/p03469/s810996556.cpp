#include <stdio.h>

int main(){
	
	char character [50];
	
	scanf("%s", &character);
	character [3] = '8';
	printf("%s\n", character);
	return 0;
}