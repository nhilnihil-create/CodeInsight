#include <cstdio>
using LL = __int128;
int arr[200005];
LL sum[200005], ans = 1e30;
int main()
{
	// freopen("AGC027-B.in", "r", stdin);
	int n, val;
	scanf("%d%d", &n, &val);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		sum[i] = (i ? sum[i - 1] : 0) + arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		LL res = (LL)val * (i + n);
		int pos = n - 1, coef = 3;
		while (pos >= 0)
		{
			res += (sum[pos] - (pos >= i ? sum[pos - i] : 0)) * (coef == 3 ? 5 : coef);
			pos -= i;
			coef += 2;
		}
		if (res < ans)
			ans = res;
	}
	printf("%lld\n", (long long)ans);
	return 0;
}
