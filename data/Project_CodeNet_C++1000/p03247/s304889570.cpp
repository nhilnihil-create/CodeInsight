#include <cstdio>
long long arr[45], x[1005], y[1005];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", x + i, y + i);
		if ((x[i] + y[i] & 1) ^ (x[0] + y[0] & 1)) {
			puts("-1");
			return 0;
		}
	}
	int m = 40;
	arr[m - 1] = arr[m - 2] = arr[m - 3] = arr[m - 4] = 1;
	for (int i = m - 5; i >= 0; i--)
		arr[i] = arr[i + 1] << 1;
	if (x[0] + y[0] & 1)
		m--;
	printf("%d\n", m);
	for (int i = 0; i < m; i++)
		printf("%lld%c", arr[i], " \n"[i + 1 == m]);
	auto abs = [&] (auto x) { return x < 0 ? -x : x; };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (abs(x[i]) <= abs(y[i])) {
				putchar(y[i] <= 0 ? 'D' : 'U');
				y[i] += arr[j] * (y[i] <= 0 ? 1 : -1);
			} else {
				putchar(x[i] <= 0 ? 'L' : 'R');
				x[i] += arr[j] * (x[i] <= 0 ? 1 : -1);
			}
		}
		puts("");
	}
	return 0;
}
