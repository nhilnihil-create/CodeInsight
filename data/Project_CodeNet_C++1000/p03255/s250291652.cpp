#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define all(v) (v).begin(), (v).end()

const ll INF = LLONG_MAX / 2ll;

ll doit(const vll& psum, const ll L, const ll X) {
	ll N = psum.size() - 1;
	ll ans = (N + L) * X;

	// do first pickups
	ans += 5ll * (psum[N] - psum[N - L]);
	if (ans > INF) return INF;
	// do all others
	for (ll j = 2, cur = N - L; cur > 0; j++, cur -= L) {
		ans += (2ll*j + 1ll) * (psum[cur] - psum[max(0ll, cur - L)]);
		if (ans > INF) return INF;
	}
	return ans;
}

int main() {
	ll N, X;
	scanf("%lld %lld", &N, &X);
	vll pos(N);
	for (ll &p : pos) scanf("%lld", &p);
	vll psum(1 + N, 0);
	partial_sum(all(pos), psum.begin() + 1);

	ll ans = LLONG_MAX;
	for (int L = 1; L <= N; L++)
		ans = min(ans, doit(psum, L, X));
	printf("%lld\n", ans);
	return 0;
}