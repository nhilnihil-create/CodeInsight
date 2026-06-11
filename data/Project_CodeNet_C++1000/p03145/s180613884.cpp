#include <stdio.h>

int main () {
	int AB, BC, CA, area;
	scanf("%d%d%d", &AB, &BC, &CA);
	area = (AB*BC)/2;
	printf("%d", area);
	return 0;
}