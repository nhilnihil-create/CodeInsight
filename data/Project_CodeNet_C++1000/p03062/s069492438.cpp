#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	ll minusNum = 0;
	ll minV = 9223372036854775807LL;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) minusNum++;
		sum += abs(a[i]);		
		if (abs(a[i]) <= minV) {
			minV = abs(a[i]);
		}
	}
	if (minusNum % 2 == 0) {
		cout << sum << endl;
	}
	else {
		sum -= 2 * minV;
		cout << sum << endl;
	}
	return 0;
}