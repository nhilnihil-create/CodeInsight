#include <stdio.h>

int main(){
	char date[11];
	scanf("%[^\n]", date);
	
	date[4]='/';
	date[7]='/';
	date[3] += 1;

	printf("%s", date);
	return 0;
}
