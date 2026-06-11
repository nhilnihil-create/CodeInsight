#include <stdio.h>
 
int main () {
	int n, a, b, num1, num2, num3, num4, num5;
	int sum = 0;
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 1; i <= n; i++) {
		num1 = i % 10;
		num2 = (i / 10) % 10;
		num3 = (i / 100) % 10;
		num4 = (i / 1000) % 10;
		num5 = (i / 10000) % 10;
		if ((num1+num2+num3+num4+num5) >= a && (num1+num2+num3+num4+num5) <= b) {
			sum += i;
		}
	}
	printf("%d\n", sum);	
	return 0;
}