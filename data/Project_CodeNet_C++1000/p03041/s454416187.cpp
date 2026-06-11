#include <stdio.h>

int main() {
	
	int N;
	int K;
	char S[100];
	
	scanf("%d %d %s", &N, &K, S);
	S[K-1] = S[K-1] + 32;
	
	printf("%s", S);
	
	return 0;
}