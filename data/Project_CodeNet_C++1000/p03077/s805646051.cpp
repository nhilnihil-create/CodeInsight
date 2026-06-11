#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	const ll p = 5;
	ll minCapa = 9223372036854775807LL;
	vector<ll> capacity(p);
	for (ll i = 0; i < p; i++) {
		cin >> capacity[i];
		minCapa = min(minCapa, capacity[i]);
	}

	ll tmp;
	if (n % minCapa == 0) tmp = n / minCapa;
	else tmp = n / minCapa + 1;

	cout << tmp + p - 1 << endl;
	return 0;
}