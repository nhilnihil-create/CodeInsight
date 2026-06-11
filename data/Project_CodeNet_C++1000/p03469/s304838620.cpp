#include <stdio.h>

	int main() {
		char ymd[11];
		
		scanf("%s", &ymd);

		ymd[3] = '8';
		
		printf("%s\n", ymd);
		
		return 0;
	}