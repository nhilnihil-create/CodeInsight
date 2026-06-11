#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, x; cin >> n >> x;
	vector<ll> m(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> m[i];
		sum += m[i];
	}
	sort(m.begin(), m.end());
	x -= sum;
	cout << x / m[0] + n << endl;
	return 0;
}