#include<cstdio>
typedef long long ll;
int n;
int masks[110];
ll p[110][15];
int num_bits[2000];
int numBits(int x)
{
	int ret = 0;
	while (x) { ret += (x & 1); x >>= 1; }
	return ret;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2000; i++) num_bits[i] = numBits(i);
	for (int i = 1; i <= n; i++)
	{
		int m = 0;
		for (int j = 1; j <= 10; j++)
		{
			int v;
			scanf("%d", &v);
			m = m * 2 + v;
		}
		masks[i] = m;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 10; j++) scanf("%lld", &p[i][j]);
	}
	bool flag = false;
	ll ans = 0;
	for (int m = 1; m < (1 << 10); m++)
	{
		ll tot = 0;
		for (int i = 1; i <= n; i++)
		{
			tot += p[i][num_bits[m & masks[i]]];
		}
		if (!flag || ans < tot)
		{
			flag = true; ans = tot;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
