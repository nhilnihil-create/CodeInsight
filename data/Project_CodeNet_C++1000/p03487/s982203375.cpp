#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	map<ll, ll>a;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (a.count(x))a.at(x)++;
		else a[x] = 1;
	}
	ll ans = 0;
	for (auto b : a) {
		if (b.first < b.second)ans += b.second - b.first;
		else if (b.first > b.second)ans += b.second;
	}
	cout << ans << endl;
}