#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100100
ll a[sz];
ll ans[sz];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n, k; cin >> n >> k;
	for (ll i = 0; i < n; ++i)
		cin >> a[i];
	ans[0] = 0;
	for (ll i = 1; i < n; i++)
	{
		ans[i] = ans[i - 1] + abs(a[i - 1] - a[i]);
		for (ll j = i - 2; j >= i - k && j > -1; j--)
			ans[i] = min(ans[i], ans[j] + abs(a[j] - a[i]));
	}
	cout << ans[n - 1];
	return 0;
}