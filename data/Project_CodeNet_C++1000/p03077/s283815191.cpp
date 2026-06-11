#include <stdio.h>
long long n, m;
long long a[5];
int main() {
	scanf("%lld", &n);
	m = n;
	for (int i = 0; i < 5; i++) {
		scanf("%lld", a + i);
		if (m > a[i])m = a[i];
	}
	printf("%lld\n", (n - 1) / m + 5);
}