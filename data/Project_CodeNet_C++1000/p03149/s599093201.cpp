#include<stdio.h>
int main(void)
{
	int N[3];
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &N[i]);
		if (N[i] != 1 && N[i] != 9 && N[i] != 7 && N[i] != 4) {
			printf("NO"); 
			return 0;
		}
		sum = sum + N[i];

	}

	if (sum == 21) {
		printf("YES");
	}
	else
		printf("NO");


	return 0;
}