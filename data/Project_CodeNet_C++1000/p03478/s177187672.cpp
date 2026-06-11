#include <stdio.h>

int main () {
	int n, a, b, dig1, dig2, dig3, dig4, dig5;
	int sum = 0;
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 1; i <= n; i++) {
		dig1 = i%10;
		dig2 = (i/10)%10;
		dig3 = (i/100)%10;
		dig4 = (i/1000)%10;
		dig5 = (i/10000)%10;
		if ((dig1+dig2+dig3+dig4+dig5) >= a && (dig1+dig2+dig3+dig4+dig5) <= b) {
			sum += i;
		}
	}
	printf("%d", sum);
	
	
	return 0;
}