#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
using ll = long long;

ll X[200010], N, XV;

ll f(ll v) {
	if (v < 1) {
		return LLONG_MAX;
	}
	ll t = 1, k = v, ans = 0;
	for (int i = N - 1;i >= 0;i--) {
		if (t == 1) {
			ans += X[i] * 5;
		}
		else {
			ans += X[i] * (t * 2LL + 1LL);
		}
		k--;
		if (k == 0)k += v, t++;
	}
	return ans + v * XV;
}

int main() {
	cin >> N >> XV;
	for (int i = 0;i < N;i++) {
		cin >> X[i];
	}
	
	ll lv = 0, rv = N + 1, l3, r3, ls, rs;
	for (int zz = 0;zz < 100;zz++) {
		ls = (lv * 2 + rv) / 3;
		rs = (lv + rv * 2) / 3;
		l3 = f(ls);
		r3 = f(rs);
		if (l3 < r3) {
			rv = rs;
		}
		else {
			lv = ls;
		}
	}
	cout << min(l3, r3) + XV * N << endl;
}