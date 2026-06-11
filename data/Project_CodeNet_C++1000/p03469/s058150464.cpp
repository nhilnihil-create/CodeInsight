#include <stdio.h>

int main() {
	char date[12];
	
	scanf("%s", date);
	
	date[0] = '2';
	date[1] = '0';
	date[2] = '1';
	date[3] = '8';
	
	printf("%s\n", date);
	
	return 0;
}