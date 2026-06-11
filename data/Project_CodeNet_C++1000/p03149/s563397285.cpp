#include<stdio.h>
int main(void)
{
	int N[4],count[10];
	for (int i = 0; i < 10; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &N[i]);
		count[N[i]]++;
	}
	if (count[1] == 1 && count[4] == 1 && count[7] == 1 && count[9] == 1) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}