#include<cstdio>

int main() {

	int n, k;

	scanf("%d%d", &n, &k);

	if (n >= 2 * k - 1) puts("YES");
	else puts("NO");

	return 0;
}