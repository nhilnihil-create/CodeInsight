#include <stdio.h>

int main(){
	
	char date2[10];
	
	scanf("%s", &date2);
	date2[0] = '2';
	date2[1] = '0';
	date2[2] = '1';
	date2[3] = '8';
	
	printf("%s", date2);
	
	return 0;
	
}