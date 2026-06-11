#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll a, b, k; cin >> a >> b >> k;
	map<ll, ll> mp;
	for (int i = a; i < min(b, a + k); i++) {
		mp[i] = 1;
	}
	for (int i = max(a, b - k + 1); i <= b; i++) {
		mp[i] = 1;
	}
	for (auto u : mp) {
		cout << u.first << endl;
	}
    return 0;
}