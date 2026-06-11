#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
	int x = 0, fh = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') fh = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return x * fh;
}
const int N = 1e5 + 10;
vector<pair<int, int> > g[N];
queue<int> q;
int n, x, y, d, i, col[N], vis[N];
int main() {
	n = read();
	for (i = 1; i < n; i++) {
		x = read(); y = read(); d = read();
		g[x].push_back(make_pair(y, d));
		g[y].push_back(make_pair(x, d));
	}
	q.push(1);
	col[1] = vis[1] = 1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (i = 0; i < g[x].size(); i++) {
			if (vis[g[x][i].first]) continue;
			vis[g[x][i].first] = 1;
			if (g[x][i].second & 1) col[g[x][i].first] = col[x] ^ 1;
			else col[g[x][i].first] = col[x];
			q.push(g[x][i].first);
		}
	}
	for (i = 1; i <= n; i++) cout << col[i] << '\n';
	return 0;
}