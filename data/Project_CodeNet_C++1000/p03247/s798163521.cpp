#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
int _min(int x, int y) {return x < y ? x : y;}
int _max(int x, int y) {return x > y ? x : y;}
int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}

struct node {
	int x, y;
} a[1100];
char ans[1100][41];
int n, now, D[40];

void solve(int x) {
	++now; D[now] = x;
	for(int i = 1; i <= n; i++) {
		if(abs(a[i].x) > abs(a[i].y)) {
			if(a[i].x > 0) ans[i][now] = 'R', a[i].x -= x; 
			else ans[i][now] = 'L', a[i].x += x;
		} else {
			if(a[i].y > 0) ans[i][now] = 'U', a[i].y -= x;
			else ans[i][now] = 'D', a[i].y += x;
		}
	}
}

int main() {
	n = read();
	for(int i = 1; i <= n; i++) a[i].x = read(), a[i].y = read();
	for(int i = 30; i >= 0; i--) solve(1 << i);
	if(a[1].x || a[1].y) solve(1);
	for(int i = 1; i <= n; i++) {
		if(a[i].x || a[i].y) {puts("-1"); return 0;}
	} printf("%d\n", now);
	for(int i = 1; i <= now; i++) printf("%d ", D[i]);
	printf("\n");
	for(int i = 1; i <= n; i++) printf("%s\n", ans[i] + 1);
	return 0;
}
