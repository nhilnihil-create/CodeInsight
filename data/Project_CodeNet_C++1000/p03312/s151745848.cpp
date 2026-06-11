#include <bits/stdc++.h>
using namespace std;

#define MX 200050
typedef long long ll;
int a[MX], n;
ll sl[MX], sr[MX];
pair<ll, ll> l[MX], r[MX];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) sl[i] = sl[i - 1] + a[i];
	for(int i = n; i > 0; i--) sr[i] = sr[i + 1] + a[i];
	for(int i = 2; i < n; i++) {
		ll v = sl[i];
		int p = lower_bound(sl + 1, sl + i + 1, (v + 1) / 2) - sl;
		pair<ll, ll> res = make_pair(0, v);
		if(p < i && abs(res.first - res.second) > abs(sl[p] * 2 - v))	res = make_pair(sl[p], v - sl[p]);
		if(p > 1 && abs(res.first - res.second) > abs(sl[p - 1] * 2 - v))	res = make_pair(sl[p - 1], v - sl[p - 1]);
		l[i] = res;
	}
	for(int i = n - 1; i > 0; i--) {
		ll v = sr[i];
		int p = lower_bound(sr + i, sr + n + 1, (v + 1) / 2, greater<ll>()) - sr;
		pair<ll, ll> res = make_pair(0, v);
		if(p <= n && abs(res.first - res.second) > abs(sr[p] * 2 - v))	res = make_pair(sr[p], v - sr[p]);
		if(p > i + 1 && abs(res.first - res.second) > abs(sr[p - 1] * 2 - v))	res = make_pair(sr[p - 1], v - sr[p - 1]);
		r[i] = res;
	}
	long long res = sl[n];
	for(int i = 2; i < n - 1; i++) {
		ll mn = min(min(l[i].first, l[i].second), min(r[i + 1].first, r[i + 1].second));
		ll mx = max(max(l[i].first, l[i].second), max(r[i + 1].first, r[i + 1].second));
		res = min(res, mx - mn);
	}
	printf("%lld\n", res);
	return 0;
}
