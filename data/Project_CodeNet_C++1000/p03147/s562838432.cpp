#include <cstdio>

int main()
{
	int prev = 0;
	int curr;
	int sum = 0;

	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &curr);
		if (curr - prev > 0)
			sum += curr - prev;
		prev = curr;
	}
	printf("%d\n", sum);
	return 0;
}