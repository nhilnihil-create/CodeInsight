#include <stdio.h>

int main() {
	int AB;
	int BC;
	int CA;
	int operation;
	
	scanf("%d %d %d", &AB, &BC, &CA);
	operation = (AB*BC)/2;
	printf("%d", operation);
	
	return 0;
}