#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
const ll INF = 1LL << 60;
int main() {
	int n;
	ll a, b;
	scanf("%d%lld%lld", &n, &a, &b);
	vector<int> p(n);
	vector<ll> dp(n + 1, INF), ndp(n + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		fill(ndp.begin(), ndp.end(), INF);
		for (int j = 0; j <= n; ++j) {
			ll cost;
			if (p[i] > j) cost = a;
			else cost = b;
			ndp[j] = min(ndp[j], dp[j] + cost);
			if (j < p[i]) ndp[p[i]] = min(ndp[p[i]], dp[j]);
		}
		swap(ndp, dp);
	}
	ll ans = *min_element(dp.begin() + 1, dp.end());
	printf("%lld\n", ans);
}
