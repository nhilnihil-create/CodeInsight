#include <cstdio>

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &c, &d, &a, &b);
	printf("%d %d %d %d", a + (d - b), b + (a - c), c + (d - b), d + (a - c));
	return 0;
}
