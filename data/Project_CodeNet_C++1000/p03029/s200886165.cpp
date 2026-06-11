#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	
	int total = 0;
	total = (a * 3) + b;
	total /= 2;
	printf("%d\n", total);
	
	
	return 0;
}