#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	ll ans = 0;
	for (int j = 0; j < 29; ++j)
	{
		ll num = 0;
		vector<ll> d(n);
		for (int i = 0; i < n; ++i)
		{
			d[i] = b[i]&((1<<(j+1))-1);
		}
		sort(d.begin(), d.end());
		for (int i = 0; i < n; ++i)
		{
			ll c = a[i]&((1<<(j+1))-1);
			num += (upper_bound(d.begin(), d.end(), (1<<(j+1))-1-c) - d.begin()) - (lower_bound(d.begin(), d.end(), (1<<j)-c) - d.begin()) - 1 + n-1 - (lower_bound(d.begin(), d.end(), 3*(1<<j)-c) - d.begin());
		}
		ans += (num&1)<<j;
	}
	cout << ans << "\n";
	return 0;
}