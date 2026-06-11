#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int n;
vector<pi> r;
int cal(int a, int b) {
	a = min(a, b);
	return 2 * a;
}
int main() {
	cin >> n;
	r.pb(mp(0, 0));
	for (int i = 1; i <= n; i++) {
		int l, rs;
		scanf("%d%d", &l, &rs);
		r.pb(mp(l, 1)), r.pb(mp(rs, 2));
	}
	sort(r.begin(), r.end());
	ll ans = 0;
	int tot[3] = {0};
	for (int i = 0; i < r.size() - 1; i++) {
		ll ndis = r[i + 1].fi - r[i].fi;
		tot[r[i].se]++;
		int nr = 0;
		if (tot[0]) nr = cal(tot[2] + 1, n - tot[1]);
		else nr = cal(n - tot[1] + 1, tot[2]);
		ans += ndis * nr;
	}
	cout << ans << endl;
	return 0;
}
