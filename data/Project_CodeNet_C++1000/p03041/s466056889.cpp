#include <stdio.h>

int main(){
	int N, K, Z;
	char S[100];
	scanf("%d %d", &N, &K);
	scanf("%s", S);
	
	Z=K-1;
	S[Z]= S[Z]+32;
	printf("%s", S);
	
	return 0;
}
