#include <bits/stdc++.h>

int main()
{
	int n, less_min{1 << 30};
	scanf("%d", &n);
	std::vector<int> a(n), b(n);
	long long sum{};
	for (int i{}; i < n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		sum += a[i];
		if (b[i] < a[i] && b[i] < less_min)
			less_min = b[i];
	}
	if (less_min == 1 << 30)
		printf("0\n");
	else
		printf("%lld\n", sum - less_min);

	return 0;
}