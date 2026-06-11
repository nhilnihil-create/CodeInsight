// Making chalk mark on generator: $1
// Knowing where to make mark: $9,999
#include <bits/stdc++.h>
#define when(...) fprintf(stderr,__VA_ARGS__)
typedef long long ll;
ll read() {
	static char c;
	static ll x;
	int flag = 1;
	while (c = getchar(), !isdigit(c))
		if (c == '-') flag = 0;
	x = c - '0';
	while (c = getchar(), isdigit(c))
		x = x * 10 + c - '0';
	return flag ? x : -x;
}

struct node {
	int w, s, v;
	bool operator<(const node &rhs) const {return w + s < rhs.w + rhs.s;}
} ns[1111];
int n;
bool vis[1010][20010];
ll ans[1010][20010];
ll f(ll x, ll rem) {
	if (rem < 0) return -1e18;
	if (x == 0) return 0;
	ll &tmp = ans[x][rem];
	if (vis[x][rem]) return tmp;
	vis[x][rem] = 1;

	if (rem == 0) return tmp = 0;
	return tmp = std::max(f(x - 1, rem),
	                      f(x - 1, std::min(rem - ns[x].w, (ll)ns[x].s)) + ns[x].v);
}

signed main() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		ns[i].w = read();
		ns[i].s = read();
		ns[i].v = read();
	}
	std::sort(ns + 1, ns + 1 + n);
	printf("%lld\n", f(n, 20000));
}
