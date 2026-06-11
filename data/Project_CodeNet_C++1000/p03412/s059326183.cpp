#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	auto stand_bit = [&](int k) {
		for (auto &x : a)
		{
			x %= (1LL << (k + 1));
		}
		for (auto &x : b)
		{
			x %= (1LL << (k + 1));
		}
		sort(b.begin(), b.end());
		ll T = 1LL << k;
		ll up = 0;
		for (auto &x : a)
		{
			up += lower_bound(b.begin(), b.end(), 2 * T - x) - lower_bound(b.begin(), b.end(), T - x) + lower_bound(b.begin(), b.end(), 4 * T - x) - lower_bound(b.begin(), b.end(), 3 * T - x);
		}
		return up & 1;
	};
	ll ans = 0;
	for (int i = 28; i >= 0; --i)
	{
		ans += (1LL << i) * stand_bit(i);
	}
	cout << ans << endl;
}