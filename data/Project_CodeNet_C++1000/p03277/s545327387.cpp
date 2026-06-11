#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100005
using namespace std;

typedef long long ll;
ll n, m, k, x, go, cnt, c, ans, l, r, md, a[N], ta[N], s[200005];
vector<ll> b;
ll f(ll p) {
	ll r = 0;
	while (p >= 1) {
		r += s[p];
		p -= (p & -p);
	}
	return r;
}

void g(ll p) {
	while (p <= n * 2 + 1) {
		s[p]++;
		p += (p & -p);
	}
}
int main()
{
	ll i;
	cin >> n;
	for (i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
		ta[i] = a[i];
	}
	sort(ta + 1, ta + n + 1);
	for (i =1; i <= n; i++) {
		if (ta[i] != ta[i - 1]) b.push_back(ta[i]);
	}
	l = 0;
	r = b.size();
	go = (n * (n + 1) / 2) / 2 + 1;
	while (l < r) {
		md = (l + r) / 2;
		x = b[md];
		memset(s, 0, sizeof(s));
		c = 0;
		cnt = 0;
		g(n + 1);
		for (i =1; i <= n; i++) {
			if (a[i] <= x) cnt++;
			else cnt--;
			g(n + 1 + cnt);
			c += f(n + cnt);
		}
		if (c >= go) {
			r = md;
			ans = x;
		} else {
			l = md + 1;
		}
	}
	cout << ans;
    return 0;
}
