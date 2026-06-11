#include <stdio.h>

int main(){
	int N;
	int K;
	char name[50];
	
	scanf("%d %d", &N, &K);
	scanf("%s", &name);

	int B = K-1;
	int C = name[B]+32;
	
	name[B] = C;
	
	printf("%s", name);
	
	
	
	return 0;
}