#pragma GCC optimize("O2")
#define NDEBUG
#include <bits/stdc++.h>
#define clean(x,y) memset(x,y,sizeof(x))
#define inc(i,s,t) for(int i=s;i<=t;++i)
#define dec(i,s,t) for(int i=s;i>=t;--i)
#define debug(x) std::cerr<<(x)<<" "
typedef unsigned long long ll;
const int inf = 0x7f7f7f7f;

inline void gettime() {
	debug("Time: ");
	debug(clock()) << " ms\n";
}
inline int read() {
	static char c;
	static int x;
	while (c = getchar(), !isdigit(c));
	x = c - '0';
	while (c = getchar(), isdigit(c))
		x = (x << 1) + (x << 3) + c - '0';
	return x;
}
inline char achar() {
	static char c;
	while (c = getchar(), !isalpha(c));
	return c;
}

const ll mod = 29996224275833;
ll ans;
int n, ls[40], rs[40], vis[40];
//cnt存储了颜色染成红色的串的数目。
std::map<ll, int> cnt;
ll hash(int *ns) {
	ll code = 0;
	for (int i = 1; i <= n; ++i)
		if (vis[i])
			code = code * 52 + ns[i] - 'a', code %= mod;
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			code = code * 52 + ns[i] - 'a' + 26, code %= mod;
	return code;
}

void dfs(int x) {
	if (x > n) {
		++cnt[hash(rs)];
		// printf("%lld %d\n", hash(rs), cnt[hash(rs)]);
		return;
	}

	dfs(x + 1);
	vis[x] = 1;
	dfs(x + 1);
	vis[x] = 0;
}

//update 枚举染成蓝色的串的数量
void update(int x) {
	// printf("vis %d\n", x);
	if (x > n) {
		ans += cnt[hash(ls)];
		// printf("Adding %d %lld\n", cnt[hash(ls)], hash(ls));
		return;
	}

	update(x + 1);
	vis[x] = 1;
	update(x + 1);
	vis[x] = 0;
}

int main() {
#ifndef ONLINE_JUDGE
	std::atexit(gettime);
#endif

	n = read();
	for (int i = 1; i <= n; ++i)
		ls[i] = achar();
	for (int i = n; i >= 1; --i)
		rs[i] = achar();

	dfs(1);
	update(1);

	printf("%lld\n", ans);
}