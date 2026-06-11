#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
int x[1010];
int y[1010];
int len[33];
ll Abs(ll x){if(x < 0) return -x; return x;}
int main() {
	int n = read();
	for(int i = 1; i <= n; i++)
		x[i] = read(), y[i] = read();
	int tmp = Abs(x[1] + y[1]) & 1;
	for(int i = 1; i <= n; i++)
		if((Abs(x[i] + y[i]) & 1) != tmp)
			return puts("-1"), 0;
	printf("%d\n1", 32 - tmp);
	len[1] = 1; int N = 1;
	if(tmp) {
		for(int i = 1; i <= 30; i++) printf(" %d", len[++N] = 1 << i);
		puts("");
	} else {
		for(int i = 0; i <= 30; i++) printf(" %d", len[++N] = 1 << i);
		puts("");
	} char s[40];
	memset(s, 0, sizeof(s));
	for(int i = 1; i <= n; i++) {
		ll nx = 0, ny = 0;
		for(int j = N; j; --j) {
			ll dx = x[i] - nx, dy = y[i] - ny;
			if(Abs(dx) > Abs(dy)) {
				if(dx > 0) nx += len[j], s[j] = 'R';
				else nx -= len[j], s[j] = 'L';
			} else {
				if(dy > 0) ny += len[j], s[j] = 'U';
				else ny -= len[j], s[j] = 'D';
			}
		} printf("%s\n", s + 1);
	}
	return 0;
}