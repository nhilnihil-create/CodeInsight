#include "bits/stdc++.h"

typedef long long ll;

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::map<ll, int> mp;
	std::vector<ll> a(n);
	std::cin >> a[0];
	a[0] %= m;
	mp[a[0]]++;
	for (int i = 1; i < n; ++i)
	{
		std::cin >> a[i];
		a[i] = (a[i] + a[i - 1]) % m;
		mp[a[i]]++;
	}
	ll count = mp[0];
	for (int i = 0; i < n; ++i)
	{
		if (mp[a[i]] > 0)
		{
			mp[a[i]]--;
		}
		count += mp[a[i]];
	}
	std::cout << count << '\n';
	return 0;
}