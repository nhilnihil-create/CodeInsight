#include <cstdio>
int main() {
	int a, b, k;
	scanf ("%d%d%*d%d", &a, &b, &k);
	if (k & 1) printf ("%d", b - a);
	else printf ("%d", a - b);
}