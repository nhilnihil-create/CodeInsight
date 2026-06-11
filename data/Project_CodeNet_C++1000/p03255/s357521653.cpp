#include <algorithm>
#include <cstdio>
typedef long long ll;
typedef __int128 LL;
ll sum[200005];
int arr[200005];
int main()
{
	// freopen("AGC027-B.in", "r", stdin);
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", arr + i);
		sum[i] = sum[i - 1] + arr[i];
	}
	LL ans = 1e36;
	for (int k = 1; k <= n; k++)
	{
		LL res = (ll)k * x;
		int cur = n, coef = 3;
		while (cur)
		{
			int real = coef + (coef == 3) * 2;
			if (cur <= k)
			{
				res += (LL)real * sum[cur];
				break;
			}
			res += (LL)real * (sum[cur] - sum[cur - k]);
			cur -= k;
			coef += 2;
		}
		ans = std::min(ans, res);
	}
	printf("%lld\n", (ll)ans + (ll)n * x);
	return 0;
}
