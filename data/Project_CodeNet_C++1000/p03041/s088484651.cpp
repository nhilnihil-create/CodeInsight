#include <stdio.h>

int main () {
	int N; 
	int K;
	char S[50];
	int length;
	scanf("%d%d", &N, &K);
	scanf("%s", S);
	length = K - 1;
	S[length] += 32; 
	printf("%s", S);
	return 0;
}