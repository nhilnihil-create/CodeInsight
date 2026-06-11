#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() 
{
	ll N;
	cin >> N;
	vector<ll> X, Y;
	for (ll i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;
		X.push_back(x);
		Y.push_back(y);
	}
	bool even = (X[0] + Y[0]) % 2 == 0 ? true : false;
	for (ll i = 0; i < N; i++) {
		bool e = (X[i] + Y[i]) % 2 == 0 ? true : false;
		if (even ^ e) {
			cout << -1 << "\n";
			return 0;
		}
		if (even) X[i]--;
	}
	vector<ll> sections;
	if (even) sections.push_back(1ll);
	for (ll i = 31; i >= 0; i--) {
		sections.push_back(1ll << i);
	}
	cout << sections.size() << "\n";
	for (ll len: sections) cout << len << " "; cout << "\n";
	const ll dx[] = {1ll, -1ll, 0, 0};
	const ll dy[] = {0, 0, 1ll, -1ll};
	const char dir[] = {'R', 'L', 'U', 'D'};
	for (ll i = 0; i < N; i++) {
		string ans = "";
		if (even) ans += "R";
		for (ll j = 31; j >= 0; j--) {
			ll mind = 10000000000;
			ll idx;
			for (ll k = 0; k < 4; k++) {
				ll cur = abs(X[i] - dx[k] * (1ll << j)) + abs(Y[i] - dy[k] * (1ll << j));
				if (cur < mind) {
					mind = cur;
					idx = k;
				}
			}
			X[i] = X[i] - dx[idx] * (1ll << j); 
			Y[i] = Y[i] - dy[idx] * (1ll << j);
			ans += dir[idx];
		}				
		cout << ans << "\n";
	}
	
	return 0;
}
