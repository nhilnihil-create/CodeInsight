#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll sum(ll A) {
	ll s = 0;
	while (A > 0) {
		s += A % 10;
		A /= 10;
	}
	return s;
}

int main() {
	
	ll N;
	cin >> N;

	ll ans = INT_MAX;
	for (int i = 1; i < N; i++) {
		ll k = N - i;
		ans = min(ans, sum(i) + sum(k));
	}
	cout << ans << '\n';
	return 0;
}
