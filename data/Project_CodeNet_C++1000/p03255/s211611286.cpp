#include <cstdio>
typedef long long ll;
ll s[200032];
int main() {
	int n, x; ll W;
	scanf("%d%lld",&n,&W);
	for (int i = 0; i < n; i++) {
		scanf("%d",&x);
		s[i+1] = s[i] + x;
	}
	ll ans = 1ll << 60;
	for (int i = 1; i <= n; i++) {
		ll cost = W * i;
		for (int r = n, l, t = 0; r && cost < ans; r = l)
			cost += (s[r] - s[l = r>i ? r-i : 0]) * (t++ ? t<<1|1 : 5);
		if (cost < ans) ans = cost;
	}
	printf("%lld\n", ans + W * n);
	return 0;
}
