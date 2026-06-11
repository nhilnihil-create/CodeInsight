#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll r, d, x; cin >> r >> d >> x;
	ll prev = x;
	for (ll i = 0; i < 10; i++) {
		ll now = r * prev - d;
		cout << now << endl;
		prev = now;
	}
	return 0;
}