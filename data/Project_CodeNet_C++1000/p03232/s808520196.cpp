#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

const int mo = 1e9 + 7;

int fac[N], inv[N], sum[N];

int power(int x, int m)
{
	int nowans = 1;
	while(m)
	{
		if(m & 1)nowans = 1ll * nowans * x % mo;
		x = 1ll * x * x % mo;
		m >>= 1;
	}
	return nowans;
}

int main()
{
	int n;
	scanf("%d", &n);
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % mo;
	inv[n] = power(fac[n], mo - 2);
	for(int i = n; i; i--)
		inv[i - 1] = 1ll * inv[i] * i % mo;
	for(int i = 1; i <= n; i++)
		sum[i] = (sum[i - 1] + 1ll * i * fac[n] % mo * inv[i + 1] % mo * fac[i - 1] % mo) % mo;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		(ans += 1ll * (0ll + sum[i - 1] + sum[n - i] + fac[n]) * x % mo) %= mo;
	}
	printf("%d\n", ans);
}