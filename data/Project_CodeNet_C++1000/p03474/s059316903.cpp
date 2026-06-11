#include <stdio.h>

int main() {
	int a, b;
	char c[255];
	scanf("%d %d", &a, &b);
	
	scanf("%s", c);
	
	int count = 0;
	
	for(int i = 0; c[i] != '\0'; i++) {
		
		if(c[a]  != '-') {
			printf("No\n");
			return 0;
		}
		
		if(c[i] >= '0' && c[i] <='9') {
			count++;
		}
	}
		if(count == a+b) {
			printf("Yes\n");
		}
		
		else {
			printf("No\n");
		}

	return 0;
}
