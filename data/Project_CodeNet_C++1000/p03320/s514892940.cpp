#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll n) {
	if (n < 10) return n;
	else {
		return n % 10 + f(n / 10);
	}
}

double g(ll n) {
	return 1.0*n / f(n);
}

int main() {
	ll K;  cin >> K;
	vector<ll> sunuke;
	ll base = 1;
	for (ll i = 0; i < 15; i++) {
		for (ll j = 1; j <= 150; j++) {
			sunuke.push_back(base*(j + 1) - 1);
		}
		base *= 10;
	}
	sort(sunuke.begin(), sunuke.end());
	sunuke.erase(unique(sunuke.begin(), sunuke.end()), sunuke.end());

	for (ll i = 0; i < (ll)sunuke.size(); i++) {
		for (ll j = i + 1; j < (ll)sunuke.size(); j++) {
			if (g(sunuke[i]) > g(sunuke[j])) {
				sunuke.erase(sunuke.begin() + i);
				i--;
				break;
			}
		}
	}

	for (ll i = 0; i < K; i++) {
		cout << sunuke[i] << endl;
	}
}
