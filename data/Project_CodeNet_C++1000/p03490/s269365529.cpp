#include <bits/stdc++.h>
#define MAX_N 16000
using namespace std;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, x, y;
char s[MAX_N+5];
vector <int> d, a, b;
bool f[2][MAX_N+5], g[2][MAX_N+5];
int main() {
	scanf("%s", s);
	n = (int)strlen(s);
	read(x), read(y), s[n] = 'T';
	for (int i = 0, cnt = 0; i <= n; i++)
		if (s[i] == 'F') cnt++;
		else d.push_back(cnt), cnt = 0;
	for (int i = 0; i < (int)d.size(); i++)
		if (i&1) b.push_back(d[i]);
		else a.push_back(d[i]);
	f[0][MAX_N/2] = g[0][MAX_N/2] = true;
	for (int i = 0, c = 1; i < (int)a.size(); i++, c ^= 1)
		for (int j = 0; j <= MAX_N; j++) {
			f[c][j] = false;
			if (j-a[i] >= 0) f[c][j] |= f[c^1][j-a[i]];
			if (i && j+a[i] <= MAX_N) f[c][j] |= f[c^1][j+a[i]];
		}
	for (int i = 0, c = 1; i < (int)b.size(); i++, c ^= 1)
		for (int j = 0; j <= MAX_N; j++) {
			g[c][j] = false;
			if (j-b[i] >= 0) g[c][j] |= g[c^1][j-b[i]];
			if (j+b[i] <= MAX_N) g[c][j] |= g[c^1][j+b[i]];
		}
	return puts(f[a.size()&1][x+MAX_N/2] && g[b.size()&1][y+MAX_N/2] ? "Yes" : "No"), 0;
}
