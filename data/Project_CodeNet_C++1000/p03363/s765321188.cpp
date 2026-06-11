#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;

	vector <ll> sum(N+1, 0);
	map<ll, ll> m;
	m[0]++;
	ll ans = 0;
	for (ll ii = 0; ii < N; ++ii){
		ll a;
		cin >> a;
		sum[ii+1] = sum[ii] + a;
		m[sum[ii+1]]++;
		ans += m[sum[ii+1]] - 1;
	}

	cout << ans << endl;

	return 0;
}
