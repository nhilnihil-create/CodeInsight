#include <algorithm>
#include <cstdio>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
long long arr[45], x[1005], y[1005];
int main()
{
	// freopen("ARC103-D.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", x + i, y + i);
		if ((x[i] + y[i] ^ x[0] + y[0]) & 1)
		{
			puts("-1");
			return 0;
		}
	}
	int m = 40;
	arr[0] = arr[1] = arr[2] = arr[3] = 1;
	for (int i = 4; i < m; i++)
		arr[i] = arr[i - 1] << 1;
	std::reverse(arr, arr + m);
	if (x[0] + y[0] & 1)
		m--;
	printf("%d\n", m);
	for (int i = 0; i < m; i++)
		printf("%lld%c", arr[i], " \n"[i + 1 == m]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (my_abs(y[i]) >= my_abs(x[i]))
			{
				putchar(y[i] >= 0 ? 'U' : 'D');
				y[i] += arr[j] * (y[i] >= 0 ? -1 : 1);
			}
			else
			{
				putchar(x[i] >= 0 ? 'R' : 'L');
				x[i] += arr[j] * (x[i] >= 0 ? -1 : 1);
			}
		}
		puts("");
	}
	return 0;
}
