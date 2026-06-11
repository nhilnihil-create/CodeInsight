#include <cstdio>
#include <cmath>

int arr[15], n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	int ans = pow(3, n), prd = 1;
	for (int i = 0; i < n; ++i)
		if (arr[i] % 2 == 0) prd *= 2;
	printf("%d", ans - prd);
	return 0;
}
