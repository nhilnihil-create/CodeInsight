// AGC_023_A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)

int main()
{
	int n;
	cin >> n;

	vector<ll> v(n);
	forn(i, n) cin >> v[i];

	map<ll, ll> mp;
	vector<ll> sum(n+1, 0);

	// sum
	forn(i, n) sum[i+1] = sum[i] + v[i];
	forn(i, n+1) ++mp[sum[i]];

	ll ans = 0;
	for(auto item : mp) {
		ll num = item.second;
		ans += num * (num - 1) / 2;
	}

	cout << ans << "\n";


	return 0;
}