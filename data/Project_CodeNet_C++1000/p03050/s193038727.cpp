
// D - DivRem Number

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll N;
	cin >> N;

	ll ans = 0;

	for (ll q=1; q*q<N; q++) {
		ll r = q;
		if ((N - r) % q == 0) {
			ll m = (N - r) / q;
			if (N % m == r) {
				ans += (N - q) / q;
			}
		}
	}

	cout << ans << endl;

	return 0;
}