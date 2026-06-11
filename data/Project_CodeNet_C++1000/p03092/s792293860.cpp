#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const long long INF = 1e18;
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
ll dp[MAXN][MAXN];
int n, f, b, a[MAXN];
int main() {
	read(n), read(f), read(b);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 0; i <= n; i++)
	for (int j = 0; j <= n; j++)
		dp[i][j] = INF;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= n; j++) {
		ll tmp = dp[i - 1][j];
		if (tmp == INF) continue;
		if (a[i] > j) {
			chkmin(dp[i][j], tmp + f);
			chkmin(dp[i][a[i]], tmp);
		} else chkmin(dp[i][j], tmp + b);
	}
	ll ans = INF;
	for (int i = 0; i <= n; i++)
		chkmin(ans, dp[n][i]);
	writeln(ans);
	return 0;
}