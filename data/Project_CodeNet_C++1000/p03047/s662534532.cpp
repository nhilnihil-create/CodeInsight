#include<stdio.h>
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	if(N >= K) printf("%d", N-K+1);
	else printf("0");
	
	return 0;
}