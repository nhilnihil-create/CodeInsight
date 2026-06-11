#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
typedef pair<string, string> P;
const ll MOD = 1000000007LL;
ll x[200001];
ll sum[200001];
int main() {
	int N;
	ll X;
	cin >> N >> X;
	for (int i = 0; i < N; i++) cin >> x[i];
	reverse(x, x + N);
	sum[0] = x[0];
	for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + x[i];
	ll ans = 0;
	bool init = 1;
	for (int k = 1; k <= N; k++) {
		int x = 0;
		ll t = 0;
		for (int i = 0; i < N; i += k) {
			int l = k*x, r = min(k*(x + 1) - 1, N - 1);
			ll s = sum[r];
			if (l > 0) s -= sum[l - 1];
			if (x == 0) t += 5 * s;
			else t += (2 * (x + 1) + 1)*s;
			x++;
		}
		if (init) ans = t + k*X, init = 0;
		else ans = min(ans, t + k*X);
	}
	cout << ans + N*X << endl;
}