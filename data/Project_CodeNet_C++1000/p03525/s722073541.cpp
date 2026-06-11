#include <iostream>
#include <algorithm>

#define N 60

int arr[N], cnt[N], n, m;

int main()
{
	scanf("%d", &n);
	cnt[0] = 1;
	for(int i = 0; i < n; ++i)
	{
		int x; scanf("%d", &x);
		cnt[x] ++;
	}

	n = 0;
	for(int k = 0; k <= 12; ++k)
	{
		if(cnt[k] > 2)
		{
			printf("0\n");
			return 0;
		}
		if(cnt[k] == 1) arr[n ++] = k;
	}

	const int u = 1 << n;

	m = n;
	for(int k = 0; k <= 12; ++k)
		if(cnt[k] == 2)
		{
			arr[m ++] = k;
			arr[m ++] = 24 - k;
		}

	int ans = 0;
	for(int k = 0; k < u; ++k)
	{
		int cur = 0x7fffffff;
		for(int i = 0; i < m; ++i)
		{
			int x = (i < n) ? (((k >> i) & 1) ? arr[i] : 24 - arr[i]) : arr[i];
			for(int j = i + 1; j < m; ++j)
			{
				int y = (j < n) ? (((k >> j) & 1) ? arr[j] : 24 - arr[j]) : arr[j];
				int d = std::abs(x - y);
				cur = std::min(cur, std::min(d, 24 - d));
			}
		}
		ans = std::max(ans, cur);
	}

	printf("%d\n", ans);
	return 0;
}
