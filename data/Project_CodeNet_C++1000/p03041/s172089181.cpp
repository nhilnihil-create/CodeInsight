#include <stdio.h>

int main () {
	char S[55];
	int N, K;
	
	scanf("%d %d", &N, &K);
	getchar();
	scanf("%s", S);
	
	S[K-1] += +32;
	
	printf("%s\n", S);
	
	
	return 0;
}