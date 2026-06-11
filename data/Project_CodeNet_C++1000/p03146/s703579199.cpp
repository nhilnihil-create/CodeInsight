#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(ll x) {
	if (x % 2 == 0) return x / 2;
	else  return 3 * x + 1;
}

int main() {

	ll s; cin >> s;
	const ll p = 1000001;
	vector<ll> num(p, 0);
	ll a = s;
	ll cnt = 1;
	while (true) {
		num[a]++;
		if (num[a] == 2) {
			break;
		}
		ll tmp = a;
		a = func(tmp);
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}