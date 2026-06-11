#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n;
ll d[100005];
int dis[100005];
map <ll, int> MP;
int que[100005], lb, rb;
int siz[100005];
vi g[100005];
vector <pii> ans;

int main() {
	n = read();
	rep(i, n) scanf("%lld", &d[i]);
	rep(i, n) MP[d[i]] = i, siz[i] = 1;
	int rt = MP.begin() -> second;
	for (map <ll, int> :: reverse_iterator rit = MP.rbegin(); rit != MP.rend(); ++ rit) {
		int u = rit -> second; if (u == rt) break;
		ll nw = d[u] - n + 2 * siz[u];
		if (!MP.count(nw)) {puts("-1"); return 0;}
		int fa = MP[nw];
		ans.pb(mp(fa, u));
		g[fa].pb(u);
		siz[fa] += siz[u];
	}
	que[rb ++] = rt;
	memset(dis, -1, sizeof dis); dis[rt] = 0;
	while (lb < rb) {
		int u = que[lb ++];
		rep(i, g[u].size()) {
			int v = g[u][i];
			if (!~dis[v]) {
				dis[v] = dis[u] + 1;
				que[rb ++] = v;
			}
		}
	}
	ll sum = 0;
	rep(i, n) sum += dis[i];
	if (sum != d[rt]) {puts("-1"); return 0;}
	rep(i, n - 1) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	return 0;
}