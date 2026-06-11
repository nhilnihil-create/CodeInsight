#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	int n;
	cin >> n;

	vv(ll) info(n, vector<ll>(3));
	vector<ll> ping(3);
	for (int i = 0; i < n; ++i)
	{
		cin >> info[i][0] >> info[i][1] >> info[i][2];
		if (info[i][2] > 0)
		{
			ping[0] = info[i][0];
			ping[1] = info[i][1];
			ping[2] = info[i][2];
		}
	}

	for (ll x = 0; x <= 100; ++x)
	{
		for (ll y = 0; y <= 100; ++y)
		{
			ll h = ping[2] + abs(ping[0] - x) + abs(ping[1] - y);
			h = max(h, 0LL);
			int f = 1;
			for (int i = 0; i < n; ++i)
			{
				ll tmp = h - abs(info[i][0] - x) - abs(info[i][1] - y);
				tmp = max(tmp, 0LL);
				if (tmp != info[i][2])
					f = 0;
			}
			if (f)
			{
				printf("%lld %lld %lld\n", x, y, h);
				return 0;
			}
		}
	}
}

