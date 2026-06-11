#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll N; cin >> N;
	const ll u = 3500;
	ll ans1, ans2, ans3;
	for (ll h = 1; h <= u; h++) {
		for (ll n = 1; n <= u; n++) {
			double w = (double)(N * h * n) / (4 * h * n - N * n - N * h);
			if (w < 1) continue;
			if (1 <= w && floor(w) == w) {
				ans1 = h;
				ans2 = n;
				ans3 = w;
				break;
			}
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3 << endl;
    return 0;
}