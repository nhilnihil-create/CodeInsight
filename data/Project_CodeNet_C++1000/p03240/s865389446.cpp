#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n; cin >> n;
	vector<int> x(n), y(n), h(n);
	int t;
	REP(i, n) {
		cin >> x[i] >> y[i] >> h[i];
		if (h[i] > 0) t = i;
	}

	REP(cy, 101) REP(cx, 101) {
		ll ch = h[t] + abs(x[t] - cx) + abs(y[t] - cy);
		ch = max(ch, 0LL);
		bool ok = true;
		REP(k, n) {
			ll tmp = ch - abs(x[k] - cx) - abs(y[k] - cy);
			if (h[k] != max(tmp, 0LL))
				ok = false;
		}
		if (ok) {
			cout << cx << " " << cy << " " << ch << '\n';
			return 0;
		}
	}
	return 0;
}
