#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

char buf[1<<21], *p1, *p2;
#define getc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin)), p1 == p2 ? EOF : *p1++)
#define lint long long
#define pii pair<int, int>
#define mp(x, y) make_pair((x), (y))
#define isnum(x) ('0' <= (x) && (x) <= '9')
template<typename tint>
inline void readint(tint& x) {
	int f = 1; char ch = getc(); x = 0;
	for(; !isnum(ch); ch = getc()) if(ch == '-') f = -1;
	for(; isnum(ch); ch = getc()) x = x * 10 + ch - '0';
	x *= f;
}
using namespace std;
const int maxn = 1e5 + 10;

// 倍数问题扩展到剩余系下考虑
int n;

priority_queue<pii, vector<pii>, greater<pii> > q;
int dist[maxn];

void dijkstra() {
	memset(dist, 0x3f, sizeof(int) * n);
	dist[1] = 1, q.push(mp(dist[1], 1));
	while(!q.empty()) {
		pii now = q.top(); q.pop();
		if(now.second > dist[now.first]) continue;
		int x = now.first;

		int y = (x * 10) % n;
		if(dist[y] > dist[x]) dist[y] = dist[x], q.push(mp(y, dist[y]));
		y = (x + 1) % n;
		if(dist[y] > dist[x] + 1) dist[y] = dist[x] + 1, q.push(mp(y, dist[y]));
	}
}

int main() {
	readint(n);
	dijkstra();
	cout << dist[0] << endl;
	return 0;
}
