#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
	ll N, K;
	cin >> N >> K;

	vector<ll>h(N);
	for (ll i = 0; i < N; i++) cin >> h[i];

	sort(h.begin(), h.end());

	ll ans = 1e18;

	for (ll i = 0; i + K <= N; i++) {
		ll Q = h[i];
		ll W = h[i + K - 1];

		ans = min(ans, W - Q);
	}

	cout << ans << endl;
}