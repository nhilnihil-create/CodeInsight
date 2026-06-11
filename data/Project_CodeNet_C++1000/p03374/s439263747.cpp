#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
typedef long long lnt;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-48);
}
int n; lnt l, c[MAX_N+5];
lnt a[MAX_N+5], b[MAX_N+5];
lnt sl[MAX_N+5], sr[MAX_N+5];
lnt f[2][MAX_N+5], g[2][MAX_N+5];
int main() {
	read(n), read(l);
	for (int i = 1; i <= n; i++)
		read(a[i]), b[i] = l-a[i], read(c[i]);
	for (int i = 1; i <= n; i++) sl[i] = sl[i-1]+c[i];
	for (int i = n; i >= 1; i--) sr[i] = sr[i+1]+c[i];
	for (int i = 1; i <= n; i++)
		f[0][i] = max(f[0][i-1], sl[i]-a[i]), 
		f[1][i] = max(f[1][i-1], sl[i]-2*a[i]);
	f[0][n+1] = f[0][1], f[1][n+1] = f[1][1];
	for (int i = n; i >= 1; i--)
		g[0][i] = max(g[0][i+1], sr[i]-b[i]), 
		g[1][i] = max(g[1][i+1], sr[i]-2*b[i]);
	g[0][0] = g[0][1], g[1][0] = g[1][1];
	lnt mx = 0;
	for (int p = 0, q = 1; p <= n; p++, q++)
		mx = max(mx, f[0][p]+g[1][q]), 
		mx = max(mx, f[1][p]+g[0][q]);
	return printf("%lld\n", mx), 0;
}
