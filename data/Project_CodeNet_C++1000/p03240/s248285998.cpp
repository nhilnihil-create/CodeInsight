#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> vx(n), vy(n), vh(n);
	ll hPositiveIndex;
	for (ll i = 0; i < n; i++) {
		cin >> vx[i] >> vy[i] >> vh[i];
		if (0 < vh[i]) hPositiveIndex = i;
	}
	const ll p = 100;
	ll resx = -1;
	ll resy = -1;
	ll resh = -1;
	for (ll x = 0; x <= p; x++) {
		for (ll y = 0; y <= p; y++) {			
			ll h = vh[hPositiveIndex] + abs(vx[hPositiveIndex] - x) + abs(vy[hPositiveIndex] - y);
			bool ok = true;
			for (ll i = 0; i < n; i++) {
				if (0 < vh[i] && vh[i] != h - abs(vx[i] - x) - abs(vy[i] - y)) ok = false;
				if (vh[i] == 0 && h > abs(vx[i] - x) + abs(vy[i] - y)) ok = false;
			}
			if (ok) {
				resx = x;
				resy = y;
				resh = h;
			}
		}
	}
	cout << resx << " " << resy << " " << resh << endl;
	return 0;
}