#include <cstdio>

#define exit() { printf("-1"); return 0; }

typedef long long ll;

ll a[222222];

int main(void)
{
	ll n, i;

	scanf("%lld" ,&n);
	for (i = 1; i <= n; i++)
		scanf("%lld" ,&a[i]);

	if (a[1] != 0)
		exit();

	for (i = 1; i < n; i++)
		if (a[i + 1] != 1 && a[i] + 1 < a[i + 1])
			exit();

	ll ans = 0;
	for (i = 1; i <= n + 1; i++)
		if (a[i] <= a[i - 1])
			ans += a[i - 1];

	printf("%lld" ,ans);
	return 0;
}