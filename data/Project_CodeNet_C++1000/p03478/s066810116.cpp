#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int total = 0;
	for(int i = 0; i <= a; i++) {
		int syarat = 0, counter = i;
		while(counter > 0) {
			syarat += counter % 10;
			counter /= 10;
		}
		if(syarat >= b && syarat <= c){
			total += i;
		}
	}
	printf("%d\n", total);
	
	return 0;
}