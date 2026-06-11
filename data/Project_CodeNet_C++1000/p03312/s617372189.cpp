#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define se second
#define pll pair<ll, ll>
#define pii pair<int, int>


using namespace std;

const int N = 3e5 + 123;
const ll mod = 1e9 + 7;
const ll inf = 1e17;


ll n, a[N], p[N];


ll get(int l, int r) {
	return p[r] - p[l - 1];
}


ll getval(int l, int m, int r) {
	return abs(get(l, m) - get(m + 1, r));
}


int getopt(int l, int r) {
	int opt = l, L = l, R = r - 1, M; 
	pair<ll, int> ans = {inf, 0};
	while (L <= R) {
		M = (L + R) / 2;
		ans = min(ans, {abs(get(l, M) - get(M + 1, r)), M});
		if (M == R) {
			R = M - 1;
			continue;
		}
		if (getval(l, M, r) > getval(l, M + 1, r))
			L = M + 1;
		else
			R = M - 1;
	}
	return ans.se;
}


int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
	cin >> n;
	p[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
	}
	ll ans = inf;
	for (int i = 2; i <= n - 2; i++) {
		int optl = getopt(1, i), optr = getopt(i + 1, n);
		ll mx, mn;
		mx = max(max(get(1, optl), get(optl + 1, i)), max(get(i + 1, optr), get(optr + 1, n)));
		mn = min(min(get(1, optl), get(optl + 1, i)), min(get(i + 1, optr), get(optr + 1, n)));
		ans = min(ans, mx - mn);
	}
	cout << ans;
	return 0;
}
