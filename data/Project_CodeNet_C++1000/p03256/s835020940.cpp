#include <bits/stdc++.h>
using namespace std;

int fst[400010], nxt[400010], lst[400010], des[400010];
int q[400010], s[400010][2], vis[400010], cnt = 0;
char st[400010];

void add(int u, int v) {
	if (!fst[u]) fst[u] = ++cnt;
	else nxt[lst[u]] = ++cnt;
	lst[u] = cnt, des[cnt] = v;
}

int main() {

	int n, m; scanf("%d%d", &n, &m);
	scanf("%s", st + 1);
	for (int i = 1; i <= m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
		s[u][st[v] - 'A'] ++;
		s[v][st[u] - 'A'] ++;
	}
	int sum = 0, r = 0, l = 0;
	for (int i = 1; i <= n; ++i)
		if (!s[i][0] || !s[i][1]) 
			q[++r] = i, vis[i] = 1, sum ++;
	while (l <= r) {
		for (int i = fst[q[l]]; i; i = nxt[i])
			if (!vis[des[i]]) {
				s[des[i]][st[q[l]] - 'A'] --;
				if (!s[des[i]][0] || !s[des[i]][1]) {
					vis[des[i]] = 1;
					q[++r] = des[i];
					sum ++;
				}
			}
		++ l;
	}
	if (sum < n) puts("Yes");
	else puts("No");
	return 0;

}