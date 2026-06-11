#include <stdio.h>
#include <string.h>

int main() {
	int a, b, hy;
	scanf("%d %d", &a, &b);
	int x = a + b + 1;
	int y = a;
	
	char n[x];
	scanf("%s", &n);
	int length = strlen(n);
	
	for(int i = 0; i < x; i++) {
		if(n[i] == '-') {
			hy++;
		}
	}
	
	if(length == x && n[y] == '-' && hy == 1) {
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}