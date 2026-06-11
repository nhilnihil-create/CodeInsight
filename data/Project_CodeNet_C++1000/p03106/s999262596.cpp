#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll a, b, k; cin >> a >> b >> k;

	ll n = max(a, b);
	ll i = 1;
	ll order = 0;
	vector<ll> p;
	
	for (ll i = 1; i <= n; i++) {	
		if (a % i == 0 && b % i == 0) {
			order++;
			p.emplace_back(i);
		}	
	}

	sort(p.begin(), p.end(), greater<ll>());

	cout << p[k - 1] << endl;
	return 0;
}