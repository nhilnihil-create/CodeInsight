#include <iostream>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
const ll inf = 1e15;
int a, b;
ll s[100005], t[100005];
void solve() {
	ll x;
	scanf("%lld", &x);
	auto its = lower_bound(s, s + a + 2, x), itt = lower_bound(t, t + b + 2, x);
	ll ans = 1e18;
	ans = min(ans, max((*its), (*itt--)) - x);
	ans = min(ans, min(*its - x, x - *itt) + (*its--) - (*itt++));
	ans = min(ans, min(x - *its, *itt - x) + (*itt--) - *its);
	ans = min(ans, x - min(*its, *itt));
	printf("%lld\n", ans);
}
int main() {
	int q;
	scanf("%d%d%d", &a, &b, &q);
	rep(i, a) scanf("%lld", &s[i + 1]);
	rep(i, b) scanf("%lld", &t[i + 1]);
	s[0] = t[0] = -inf;
	s[a + 1] = t[b + 1] = inf;
	while (q--) solve();
	return 0;
}