#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, head[N], tot, siz[N], dis[N];
struct data{int d, id;}d[N];
struct node{int to, nex;}a[N << 1];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
bool cmp(const data & a, const data & b) {return a.d > b.d;}
void add(int x, int y) {a[++ tot].to = y; a[tot].nex = head[x]; head[x] = tot;}
void dfs(int x, int fa)
{
	for(int i = head[x]; i; i = a[i].nex)
	{
		int y = a[i].to; if(y == fa) continue;
		dis[y] = dis[x] + 1; dfs(y, x);
	}
}
signed main()
{
	n = read();
	for(int i = 1; i <= n; i ++) {d[i] = data{read(), i}; siz[i] = 1;}
	sort(d + 1, d + n + 1, cmp);
	for(int i = 1; i < n; i ++)//<n
	{
		int val = d[i].d - n + 2 * siz[i];
		int l = 1, r = n + 1, pos;//n + 1
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if(d[mid].d <= val) pos = mid, r = mid - 1;
			else l = mid + 1;
		}
		if(d[pos].d != val) {puts("-1"); return 0;}
		add(d[i].id, d[pos].id); add(d[pos].id, d[i].id); siz[pos] += siz[i];
	}
	dfs(d[n].id, 0); int sum = 0;
	for(int i = 1; i <= n; i ++) sum += dis[i];
	if(sum != d[n].d) puts("-1");
	else {for(int i = 1; i <= tot; i += 2) printf("%lld %lld\n", a[i].to, a[i + 1].to);}
	return 0;
}
