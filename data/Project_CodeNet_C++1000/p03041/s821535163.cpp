#include<stdio.h>
int main(){
	int N;
	int K;
	char S[52];
	scanf("%d %d", &N, &K);
	scanf("%s", &S);
	--K;
	S[K] = S[K] + 32;
	printf("%s", S);
	return 0;
}