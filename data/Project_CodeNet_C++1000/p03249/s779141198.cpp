#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
ll d[MAXN]; bool vis[MAXN]; map <ll, int> home;
vector <int> a[MAXN]; pair <ll, int> b[MAXN];
int f[MAXN], s[MAXN], size[MAXN];
void dfs(int pos, int fa) {
	size[pos] = 1;
	for (auto x : a[pos])
		if (x != fa) {
			dfs(x, pos);
			size[pos] += size[x];
		}
}
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		read(d[i]);
		f[i] = i, s[i] = 1;
		b[i] = make_pair(d[i], i);
		home[d[i]] = i;
	}
	sort(b + 1, b + n + 1);
	reverse(b + 1, b + n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int pos = b[i].second; vis[pos] = true;
		ll another = b[i].first + s[pos] - (n - s[pos]);
		if (home.count(another) == 0 || vis[home[another]]) {
			puts("-1");
			return 0;
		}
		int res = home[another];
		f[pos] = f[res], s[res] += s[pos];
	}
	for (int i = 1; i <= n; i++)
		if (vis[i]) {
			a[i].push_back(f[i]);
			a[f[i]].push_back(i);
		}
	dfs(1, 0);
	ll res = 0;
	for (int i = 2; i <= n; i++)
		res += size[i];
	if (res == d[1]) {
		for (int i = 1; i <= n; i++)
			if (vis[i]) printf("%d %d\n", i, f[i]);
	} else puts("-1");
	return 0;
}