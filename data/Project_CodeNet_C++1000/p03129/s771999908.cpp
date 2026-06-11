#include<stdio.h>
int main(void)
{
	int N, K,co;
	scanf("%d%d", &N, &K);
	if (N % 2 == 0) {
		co = N / 2;
	}else{
		co = (N + 1) / 2;
	}
	if (co >= K) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}