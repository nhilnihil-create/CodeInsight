#include <stdio.h>

int main () {
	char string[15];
	scanf("%s", string);
	printf("2018");
	for (int i = 4; string[i] != '\0'; i++) {
		printf("%c", string[i]);
	}
	printf("\n");
	
	
	
	return 0;
}