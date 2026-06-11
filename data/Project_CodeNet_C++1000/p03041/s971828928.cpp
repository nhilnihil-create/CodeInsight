#include <stdio.h>

int main(){
	char S [52];
	int N, K;
	scanf("%d %d\n", &N, &K);
	scanf("%s", &S);
	S[K-1] += 32;
	printf("%s\n", S);
	
	return 0;
}