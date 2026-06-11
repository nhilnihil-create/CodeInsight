#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	if (b >= c)
	{
		printf("%lld\n", b + c);
	}
	else
	{
		ll ans = 0;
		c -= b;
		ans += b * 2;
		if (a >= c)
			ans += c, c = 0;
		else
			ans += a, c -= a;
		if (c > 0) ++ans;
		printf("%lld\n", ans);
	}
	return 0;
}