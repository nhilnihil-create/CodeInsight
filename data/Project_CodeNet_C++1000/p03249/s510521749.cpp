#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
int _min(int x, int y) {return x < y ? x : y;}
int _max(int x, int y) {return x > y ? x : y;}
LL read() {
	LL s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}

struct edge {
	int x, y, next;
} f[110000], e[110000]; int len, last[110000];
struct node {
	LL x; int id;
} a[110000];
LL d[110000], sum;
int tot[110000];

bool cmp(node a, node b) {return a.x < b.x;}

void ins(int x, int y) {
	e[++len].x = x, e[len].y = y;
	e[len].next = last[x], last[x] = len;
}

void dfs(int x, int dis) {
	sum += dis;
	for(int k = last[x]; k; k = e[k].next) {
		int y = e[k].y;
		dfs(y, dis + 1);
	}
}

int main() {
	LL n = read();
	for(LL i = 1; i <= n; i++) a[i].x = read(), a[i].id = i;
	sort(a + 1, a + n + 1, cmp);
	for(LL i = 1; i <= n; i++) d[i] = a[i].x;
	for(LL i = 1; i <= n; i++) tot[i] = 1;
	len = 0;
	for(LL i = n; i > 1; i--) {
		LL u = d[i] - n + 2 * tot[i];
		int fa = lower_bound(d + 1, d + n + 1, u) - d;
		if(d[fa] != u) {puts("-1"); return 0;}
		f[++len].x = fa, f[len].y = i;
		tot[fa] += tot[i];
	} len = 0; for(int i = 1; i < n; i++) ins(f[i].x, f[i].y);
	sum = 0; dfs(1, 0);
	if(sum != d[1]) {puts("-1"); return 0;}
	for(int i = 1; i < n; i++) printf("%d %d\n", a[f[i].x].id, a[f[i].y].id);
	return 0;
}
