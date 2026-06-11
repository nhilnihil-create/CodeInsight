#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200010;
int _w;

int n, a[MAXN], f[MAXN], g[1<<26];
char s[MAXN];

int calc( int x ) {
	int ans = g[x] + 1;
	for( int i = 0; i < 26; ++i )
		ans = min(ans, g[x^(1<<i)] + 1);
	return g[x] = min(g[x], ans), ans;
}

int main() {
	_w = scanf( "%s", s );
	n = (int)strlen(s);
	for( int i = 0; i < n; ++i )
		a[i] = 1 << (s[i] - 'a');
	memset(g, 0x3f, sizeof g);
	g[0] = 0;
	int xors = 0;
	for( int i = 0; i < n; ++i )
		xors ^= a[i], f[i] = calc(xors);
	printf( "%d\n", f[n-1] );
	return 0;
}
