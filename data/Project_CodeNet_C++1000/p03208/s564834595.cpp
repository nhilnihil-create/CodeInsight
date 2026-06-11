#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N, K;
	cin >> N >> K;

	vector<ll> h(N);
	for (int i = 0; i < N; ++i) {
		cin >> h[i];
	}

	sort(h.begin(), h.end());

	ll ans = 10000000000;
	for (int i = 0; i <= N - K; ++i) {
		ans = min(ans, h[i + K - 1] - h[i]);
	}
	cout << ans << endl;

	return 0;
}