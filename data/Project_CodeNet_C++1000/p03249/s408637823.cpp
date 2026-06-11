#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define pii pair<LL, int>
using namespace std;
const int N = 1e5 + 10;

int n, m;
int a[N], b[N];
LL d[N], siz[N];
map<LL, int> Map;
priority_queue<pii> Q;

void doit(int cnt) {
	pii tmp = Q.top(); Q.pop();
	int to = Map[d[tmp.se] - (n - siz[tmp.se] * 2)];
	if (!to || tmp.se == to) puts("-1"), exit(0);
	a[cnt] = to;
	b[cnt] = tmp.se;
	if (siz[tmp.se] * 2 > n) puts("-1"), exit(0);
	siz[to] += siz[tmp.se];
}

namespace check {
	LL res = 0;
	int E, fir[N], nex[N << 1], arr[N << 1];

	void Add_Edge(int x, int y) {
		nex[++E] = fir[x];
		fir[x] = E; arr[E] = y;
	}

	void dfs(int x, int fa, LL dx) {
		res += dx;
		for (int i = fir[x]; i; i = nex[i]) {
			if (arr[i] == fa) continue;
			dfs(arr[i], x, dx + 1);
		}
	}
	
	void main() {
		for (int i = 1; i < n; ++i) {
			Add_Edge(a[i], b[i]);
			Add_Edge(b[i], a[i]);
		}
		int tmp = 1;
		for (int i = 1; i <= n; ++i) {
			if (d[i] > d[tmp]) tmp = i;
		}
		dfs(tmp, 0, 0);
		if (res != d[tmp]) puts("-1"), exit(0);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &d[i]);
		Map[d[i]] = i;
		Q.push(make_pair(d[i], i));
	}
	if (n == 1 && d[1]) return 0 * puts("-1");
	for (int i = 1; i <= n; ++i)
		siz[i] = 1;
	for (int i = 1; i < n; ++i)
		doit(i);
	check::main();
	for (int i = 1; i < n; ++i)
		printf("%d %d\n", a[i], b[i]);
	return 0;
}
