#include <bits/stdc++.h>
#define x first
#define y second
#define MAX_N 1000
using namespace std;
typedef long long lnt;
typedef pair<int,int> pii;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, f;
pii p[MAX_N+5];
char s[MAX_N+5][32];
bool chk() {
	for (int i = 1; i <= n; i++)
		if (((p[i].x+p[i].y)&1) ^ f) return false;
	return true;
}
lnt dis(pii u, pii v) {return 1LL*abs(u.x-v.x)+1LL*abs(u.y-v.y);}
bool chkL(int d, pii u, pii v) {u.x -= (1<<d); return dis(u, v) < (1LL<<d);}
bool chkR(int d, pii u, pii v) {u.x += (1<<d); return dis(u, v) < (1LL<<d);}
bool chkD(int d, pii u, pii v) {u.y -= (1<<d); return dis(u, v) < (1LL<<d);}
bool chkU(int d, pii u, pii v) {u.y += (1<<d); return dis(u, v) < (1LL<<d);}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(p[i].x), read(p[i].y);
	f = (p[1].x+p[1].y)&1;
	if (!chk()) return puts("-1"), 0;
	if (f) {
		puts("31");
		for (int i = 0; i <= 30; i++)
			printf("%d ", (1<<i));
		puts("");
	} else {
		puts("32");
		for (int i = 0; i <= 30; i++)
			printf("%d ", (1<<i));
		puts("1");
		for (int i = 1; i <= n; i++)
			p[i].x++, s[i][31] = 'L';
	}
	for (int id = 1; id <= n; id++) {
		pii c = pii(0, 0);
		for (int i = 30; ~i; i--) {
			if (chkL(i, c, p[id])) c.x -= (1<<i), s[id][i] = 'L';
			else if (chkR(i, c, p[id])) c.x += (1<<i), s[id][i] = 'R';
			else if (chkD(i, c, p[id])) c.y -= (1<<i), s[id][i] = 'D';
			else if (chkU(i, c, p[id])) c.y += (1<<i), s[id][i] = 'U';
		}
	}
	for (int i = 1; i <= n; i++, puts(""))
		for (int j = 0; j <= 30+(!f); j++) putchar(s[i][j]);
	return 0;
}