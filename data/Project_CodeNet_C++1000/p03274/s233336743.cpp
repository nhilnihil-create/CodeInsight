#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[100500];
void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	ll res = LONG_MAX;
	map<ll, ll> mp1, mp2, m1, m2;
	ll k1 = 0, k2 = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] > 0) {
			k1++;
			mp1[x[i]] = k1;
			m1[k1] = x[i];
		}
		if (x[n - i - 1] <= 0) {
			k2++;
			mp2[x[n - i - 1]] = k2;
			m2[k2] = x[n - i - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		if (x[i] <= 0)  {
			ll need = k - mp2[x[i]];
			ll t = -x[i];
			if (need > 0 && mp1[m1[need]] > 0) {
				t = min((2 * (-x[i]) + m1[need]), (-x[i]) + 2 * m1[need]);
				need = 0;
			}
			if (need == 0)
				res = min(t, res);
		}
		else {
			ll need = k - mp1[x[i]];
			ll t = x[i];
			if (need > 0 && mp2[m2[need]] > 0) {
				t = min((2 * x[i] - m2[need]), x[i] - 2 * m2[need]);
				need = 0;
			}
			if (need == 0)
				res = min(t, res);
		}
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}