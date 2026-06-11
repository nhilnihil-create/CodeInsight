#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

int n, a, b, num1, num2;

int min(int a, int b) { return a < b ? a : b; }

int main() {
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		if (x <= a) ++num1;
		if (x > a && x <= b) ++num2;
	}
	printf("%d\n", min(num1, min(num2, n - num1 - num2)));
	return 0;
}