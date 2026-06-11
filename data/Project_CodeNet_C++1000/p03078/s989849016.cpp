#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, z, k;
	cin >> x >> y >> z >> k;

	ll a[x], b[y], c[z];
	for (int i = 0; i < x; ++i) cin >> a[i];
	for (int i = 0; i < y; ++i) cin >> b[i];
	for (int i = 0; i < z; ++i) cin >> c[i];

	sort(a, a + x, greater<ll>());
	sort(b, b + y, greater<ll>());
	sort(c, c + z, greater<ll>());

	vector<ll> sums;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			for (int l = 0; l < z; ++l) {
				if (i * j * l <= k) sums.push_back(a[i] + b[j] + c[l]);
			}
		}
	}
	sort(sums.begin(), sums.end(), greater<ll>());
	for (int i = 0; i < k; ++i) cout << sums[i] << '\n';
}
