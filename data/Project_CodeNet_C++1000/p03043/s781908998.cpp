#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	ll n, k;
	cin >> n >> k;

	double ans = 0.0;
	for (ll i = 1; i <= n; ++i)
	{
		ll tmp = i;
		double  rate = 1.0/n;
		while (tmp < k)
		{
			tmp *= 2;
			rate /= 2;
		}
		ans += rate;
	}
	printf("%.12f\n", ans);
}

