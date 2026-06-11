#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
char s[MAXN][MAXN];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		scanf("\n%s", s[i] + 1);
	int ans = 0;
	for (int p = 1; p <= n; p++) {
		bool flg = true;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			flg &= s[i][j] == s[j][i];
		if (flg) ans += n;
		for (int i = 1; i <= n; i++) {
			char c = s[i][1];
			for (int j = 1; j <= n - 1; j++)
				s[i][j] = s[i][j + 1];
			s[i][n] = c;
		}
	}
	writeln(ans);
	return 0;
}