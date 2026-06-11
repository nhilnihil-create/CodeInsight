#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> x(n), y(n), h(n);
	ll index;
	for (ll i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> h[i];
		if (0 < h[i]) index = i;
	}
	const ll p = 100;
	ll ansCx, ansCy, ansH;
	for (ll cx = 0; cx <= p; cx++) {
		for (ll cy = 0; cy <= p; cy++) {
			ll ansH = h[index] + abs(x[index] - cx) + abs(y[index] - cy);
			bool ok = true;
			for (ll i = 0; i < n; i++) {
				if (0 < h[i] &&  h[i] != ansH - abs(x[i] - cx) - abs(y[i] - cy)) {
					ok = false;
				}
				if (0 == h[i] && h[i] < ansH - abs(x[i] - cx) - abs(y[i] - cy)) {
					ok = false;
				}
			}
			if (ok) {
				ansCx = cx;
				ansCy = cy;
				cout << ansCx << " " << ansCy << " " << ansH << endl;
				return 0;				
			}
		}
	}	
	return 0;
}