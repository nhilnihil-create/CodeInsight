#include <stdio.h>

int main(){
	char string[55];
	int a, b;
	scanf("%d %d", &a, &b);
	getchar();
	scanf("%[^\n]", &string);
	string[b-1] +=  32;
	printf("%s", string);
	
	
	return 0;
}