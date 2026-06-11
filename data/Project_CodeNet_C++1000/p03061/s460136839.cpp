#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> div(ll n) {
	vector<ll> res;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n)
				res.push_back(n / i);
		}
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 1;
	for (int j = 0; j < 2; j++) {
		vector<ll> p = div(a[j]);
		for (auto v : p) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] % v != 0) {
					cnt++;
				}
			}
			if (cnt <= 1 && ans < v) {
				ans = v;
			}
		}
	}
	cout << ans << endl;
	return 0;
}