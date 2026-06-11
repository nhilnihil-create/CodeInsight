#include <stdio.h>

int main (){
	char date[11];
	scanf("%s", date);
	
	date[3] = '8';
	
	printf("%s", date);
	
	return 0;
}