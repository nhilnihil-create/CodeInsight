#include <stdio.h>

int main () {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	
	
	int allSum = 0;
	for (int i = 1; i <= n; i++) {
		int digitSum = 0;
		int temp = i;
		while (temp != 0) {
			digitSum = digitSum + temp % 10;
			temp /= 10;
		}
		if (digitSum >= a && digitSum <= b) {
			allSum += i; 
		}
	}
	
	printf("%d", allSum);
	
	return 0;
}