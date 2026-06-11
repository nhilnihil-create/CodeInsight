#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, k; cin >> n >> k;
	
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	sort(h.begin(), h.end(),greater<ll>());

	ll ans = 9223372036854775807LL;
	for (int i = 0; i < n - k + 1; i++) {
		ll tmp = h[i] - h[i + k - 1];
		ans = min(ans, tmp);
	}
	
	cout << ans << endl;
	return 0;
}