#include <bits/stdc++.h>
#define R register
#define mp make_pair
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
const int mod = 998244353, N = 110000;

int n, size[N];
ll d[N], g[N];
vector<int> to[N];
map<ll, int> rev;

inline int addMod(int a, int b) {
	return (a += b) >= mod ? a - mod : a;
}

inline ll quickpow(ll base, ll pw) {
	ll ret = 1;
	while (pw) {
		if (pw & 1) ret = ret * base % mod;
		base = base * base % mod, pw >>= 1;
	}
	return ret;
}

template <class T>
inline void read(T &x) {
	x = 0;
	char ch = getchar(), w = 0;
	while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x = w ? -x : x;
	return;
}

void dfs(int now) {
	for (auto &v : to[now]) {
		printf("%d %d\n", now, v);
		dfs(v);
	}
	return;
}

int main() {
	read(n);
	for (R int i = 1; i <= n; ++i)
		read(d[i]), rev[d[i]] = i;
	while (rev.size() > 1) {
		auto it = prev(rev.end());
		size[it->second] += 1;
		ll w = 2 * size[it->second] - n + it->first;
		auto f = rev.find(w);
		if (f == it || f == rev.end())
			return printf("-1\n"), 0;
		to[f->second].push_back(it->second);
		size[f->second] += size[it->second];
		g[f->second] += g[it->second] + size[it->second];
		rev.erase(it);
	}
	int rt = rev.begin()->second;
	if (g[rt] != d[rt]) return printf("-1\n"), 0;
	dfs(rt);
	return 0;
}