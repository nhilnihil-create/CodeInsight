#include <stdio.h>

int main () {
	char str[10];
	scanf("%s", &str);
	
	printf("2018/01/");
	for (int i = 8; i < 10; i++) {
		printf("%c", str[i]);
	}
	
	return 0;
}