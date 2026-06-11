
// C - Candles

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

vector<ll> L, R;

int main() {
	int N, K;
	cin >> N >> K;

	L.push_back(0);
	R.push_back(0);
	for (int i=0; i<N; i++) {
		int x;
		cin >> x;
		if (x == 0) K--;
		else if (x < 0) L.push_back(-x);
		else R.push_back(x);
	}

	sort(L.begin(), L.end());

	ll ans = INF;

	// L -> R
	for (int i=0; i<=K && i < L.size(); i++) {
		if (K-i >= R.size()) continue;

		ll time = L[i] * 2 + R[K-i];
		ans = min(ans, time);
	}

	// R -> L
	for (int i=0; i<=K && i < R.size(); i++) {
		if (K-i >= L.size()) continue;

		ll time = R[i] * 2 + L[K-i];
		ans = min(ans, time);
	}

	cout << ans << endl;

	return 0;
}