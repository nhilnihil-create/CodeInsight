#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
bool work(ll a, ll b, ll c, ll d) {
	if (b > a || b > d) return false;
	if (b <= c) return true;
	ll g = __gcd(b, d);
	return b - ((g - a % g == 0) ? g : (g - a % g)) <= c;
}
int main() {
	int T; read(T);
	while (T--) {
		ll a, b, c, d;
		read(a), read(b), read(c), read(d);
		if (work(a, b, c, d)) puts("Yes");
		else puts("No");
	}
	return 0;
}