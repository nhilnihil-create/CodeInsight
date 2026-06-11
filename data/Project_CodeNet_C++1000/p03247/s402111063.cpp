#include <bits/stdc++.h>

using namespace std;

inline void Boost() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}
typedef long long int ll;
typedef long double ld;

int main() {
	Boost();

	int n; cin >> n;
	int par = 0;
	vector < pair < ll, ll > > v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
		par += abs(v[i].first + v[i].second) % 2;
	}

	if (par != 0 && par != n) {
		cout << -1;
		return 0;
	}

	int m = 35 + (par == 0);
	vector < ll > pwr(m);
	
	if (par == 0) {
		pwr[0] = 1;
	}

	ll P = 1;
	for (int i = (par == 0); i < m; ++i, P *= 2) pwr[i] = P;

	cout << m << "\n";
	for (auto x : pwr) cout << x << " ";
	cout << "\n";

	for (int i = 0; i < n; ++i) {
		ll x, y;
		x = y = 0;

		string moves = "";
		for (int j = m - 1; j >= 0; --j) {
			if (abs(x - v[i].first) >= abs(y - v[i].second)) {
				if (x - v[i].first < 0) {
					moves += "R";
					x += pwr[j];
				} else {
					moves += "L";
					x -= pwr[j];
				}
			} else {
				if (y - v[i].second >= 0) {
					moves += "D";
					y -= pwr[j];
				} else {
					moves += "U";
					y += pwr[j];
				}
			}
		}
		reverse(moves.begin(), moves.end());
		cout << moves << "\n";
	}
	return 0;
}