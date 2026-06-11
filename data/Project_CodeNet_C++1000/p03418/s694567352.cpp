#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(void)
{
	ll n, k, i, ans = 0;

	scanf("%lld %lld" ,&n, &k);

	if (k == 0)
	{
		printf("%lld" ,n * n);
		return 0;
	}

	for (i = k + 1; i <= n; i++)
	{
		ll st = n / i;
		ans += (i - k) * st;
		ll left = st * i + k;

		ans += max(0LL, n - left + 1);
	}

	printf("%lld" ,ans);
	return 0;
}