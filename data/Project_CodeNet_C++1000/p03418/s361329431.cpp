#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	ll res = 0;
	if (k == 0) {
		res = (ll)n * (ll)n;
	} else {
		rep (i, k + 1, n + 1) { // b
			res += (i - k);
			ll tmp = min(2 * i, n) - min((i + k), n);
			ll x = n / i;
			res += tmp * (x - 1);
			res += max<ll>(0, n - (x * i + k - 1));
		}
	}

	cout << res << endl;
	return 0;
}
