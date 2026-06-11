
// A - Two Abbreviations

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll get_gcd(ll x, ll y) {
	if (y > 0) return get_gcd(y, x % y);
	else return x;
}

ll get_lcm(ll x, ll y) {
	return x / get_gcd(x, y) * y;
}

int main() {
	int N, M;
	cin >> N >> M;

	string S, T;
	cin >> S;
	cin >> T;

	ll L = get_lcm(N, M);

	ll ans;

	if (N > M) {
		swap(S, T);
		swap(N, M);
	}

	ll s = L / N;
	ll t = L / M;
	bool ok = true;
	for (int i=0; i<N; i++) {
		if ((i * s) % t != 0) continue;

		if (S[i] != T[(i * s) / t]) {
			ok = false;
		}
	}

	if (ok) ans = L;
	else ans = -1;

	cout << ans << endl;

	return 0;
}