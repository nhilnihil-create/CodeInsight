#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, k; cin >> n >> k;
	vector<ll> c(n);
	for (ll i = 0; i < n; ++i) {
		cin >> c[i];
	}
	ll a = n - 1;
	ll b = k - 1;
	cout << (a + b - 1) / b << endl;
	return 0;
}