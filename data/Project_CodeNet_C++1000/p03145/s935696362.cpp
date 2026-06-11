#include <stdio.h>
int a, b, c, x;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	if (a < c && b < c)x = a * b;
	if (a < b && c < b)x = a * c;
	if (b < a && c < a)x = b * c;
	printf("%d\n", x / 2);
}