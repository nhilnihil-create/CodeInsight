#include <stdio.h>
int main(){
	int N;
	int K;
	char STRING[52];
	scanf("%d %d", &N, &K);
	scanf("%s", STRING);
	STRING[K-1]  = STRING[K-1]+32;
	printf("%s", STRING );
	
	return 0;
}