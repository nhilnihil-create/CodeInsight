#include <stdio.h>

int main() {
	int a, b;	
	scanf("%d %d", &a, &b);
	
	int sum = 1;
	
	for(int i = 0; i < a; i++) {
			if(sum*2 < sum+b) {
				sum = sum*2;
			}
			else if (sum*2 > sum+b) {
				sum += b;
			}
			else {
				sum = sum * 2;
			}
		}
	printf("%d", sum);

	return 0;
}
