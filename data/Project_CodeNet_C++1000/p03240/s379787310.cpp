#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

vector<tuple<ll, ll, ll>>vec;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n; cin >> n;
	vector<int> x(n), y(n), h(n);
	int t;
	REP(i, n) {
		cin >> x[i] >> y[i] >> h[i];
		if (h[i] > 0) t = i;
	}

	REP(i, 101) REP(j, 101) {
		ll H = h[t] + abs(x[t] - j) + abs(y[t] - i);
		H = max(H, 0LL);
		bool ok = true;
		REP(k, n) {
			ll HH = H - abs(x[k] - j) - abs(y[k] - i);
			HH = max(HH, 0LL);
			if (h[k] != HH)
				ok = false;
			// ok &= (h[k] == HH);
		}
		if (ok) {
			cout << j << " " << i << " " << H << '\n';
			return 0;
		}
	}
	return 0;
}
