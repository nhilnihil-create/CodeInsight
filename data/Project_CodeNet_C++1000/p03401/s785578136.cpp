#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll sum = 0;
	for (ll i = 0; i <= n - 1; i++) {
		sum += abs(a[i + 1] - a[i]);
	}
	sum += abs(a[n]);
	for (ll i = 1; i <= n; i++) {
		ll tmpSum = 0;
		tmpSum += sum;
		tmpSum -= abs(a[i - 1] - a[i]);
		if (i != n) {
			tmpSum -= abs(a[i] - a[i + 1]);
			tmpSum += abs(a[i - 1] - a[i + 1]);
		}
		else {
			tmpSum -= abs(a[i]);
			tmpSum += abs(a[i - 1]);
		}
		cout << tmpSum << endl;
	}
	return 0;	
}