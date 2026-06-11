#include<cstdio>

typedef long long ll;
const int MAX_N = 100000;
ll x[MAX_N];
ll v[MAX_N];
ll m[4][MAX_N+1];

ll max(ll a, ll b) {
	return a > b ? a : b;
}
int main() {
	int n;
	ll c;
	scanf("%d %lld", &n, &c);
	for(int i=0;i<n;i++) {
		scanf("%lld %lld", &x[i], &v[i]);
	}
	ll v_sum = 0;
	ll max0 = 0;
	ll max1 = 0;
	m[0][0] = m[1][0] = 0;
	for(int i=1;i<=n;i++) {
		v_sum += v[i-1];
		ll v0 = v_sum - x[i-1];
		ll v1 = v_sum - 2 * x[i-1];
		if(max0 < v0) max0 = v0;
		if(max1 < v1) max1 = v1;
		m[0][i] = max0;
		m[1][i] = max1;
	}
	v_sum = 0;
	ll max2 = 0;
	ll max3 = 0;
	m[2][n] = m[3][n] = 0;
	for(int i=n-1;i>=0;i--) {
		v_sum += v[i];
		ll v2 = v_sum - (c - x[i]);
		ll v3 = v_sum - 2 * (c - x[i]);
		if(max2 < v2) max2 = v2;
		if(max3 < v3) max3 = v3;
		m[2][i] = max2;
		m[3][i] = max3;
	}
	ll ans = 0;
	for(int i=0;i<=n;i++) {
		ll v = max(max(max(m[0][i], m[2][i]), m[0][i]+m[3][i]), m[1][i]+m[2][i]);
		if(ans < v) ans = v;
	}
	printf("%lld\n", ans);
	return 0;
}
