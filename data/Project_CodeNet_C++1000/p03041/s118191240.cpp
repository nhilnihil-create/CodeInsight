#include <stdio.h>
int main(){

	int z, k;
	char A, B, C;
	char string[55];
	
	scanf("%d %d", &z, &k);
	getchar();
	scanf("%s", &string);
	
	string[k-1] += 32;
	printf("%s", string);
	return 0;
}

