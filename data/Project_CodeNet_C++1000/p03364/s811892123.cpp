#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (int)(n); i ++)
#define re0(i, n) for (rint i = 0; i < (int) n; i ++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint register int
using namespace std;

typedef long long lo;

template<typename tp> inline void read(tp &x) {
    x = 0; char c = getchar(); int f = 0;
    for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
    for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if (f) x = -x;
}
const int N = 555;
int n;
char str[N][N], T[N][N];
int main(void) {
	read(n);
	rep (i, n) scanf("%s", str[i] + 1);
	int ans = 0;
	rep (A, n) {
		rep (i, n) rep (j, n) 
			T[i][j] = str[(i + A - 1) % n + 1][j];
		int ok = 1;
		rep (i, n) rep (j, n) ok &= T[i][j] == T[j][i];
		ans += ok * n;
	}
	cout << ans << "\n";	
}
