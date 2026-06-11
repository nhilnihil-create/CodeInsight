#include <stdio.h>

int main(){
	char date[11];
	scanf("%[^\n]", date);
	getchar();

	date[3] = '8';
	printf("%s\n", date);
	return 0;
}
