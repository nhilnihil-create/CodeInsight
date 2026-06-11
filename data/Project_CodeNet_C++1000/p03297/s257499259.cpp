#define NDEBUG
#include <bits/stdc++.h>
#define clean(x,y) memset(x,y,sizeof(x))
#define inc(i,s,t) for(int i=s;i<=t;++i)
#define dec(i,s,t) for(int i=s;i>=t;--i)
#define debug(x) std::cerr<<(x)<<" "
typedef long long ll;
const int inf = 0x7f7f7f7f;

inline void gettime() {
	debug("Time: ");
	debug(clock()) << " ms\n";
}
inline ll read() {
	static char c;
	static ll x;
	while (c = getchar(), !isdigit(c));
	x = c - '0';
	while (c = getchar(), isdigit(c))
		x = (x << 1) + (x << 3) + c - '0';
	return x;
}
inline char achar() {
	static char c;
	while (c = getchar(), !isalpha(c));
	return c;
}

void ok() {puts("Yes");}
void no() {puts("No");}

ll gcd(ll x, ll y) {
	return !y ? x : gcd(y, x % y);
}

void solve() {
	ll A = read(), B = read(), C = read(), D = read();
	if (B > A || B > D)
		return no();
	if (B <= C)
		return ok();

	if ((A - C - 1) / gcd(B, D) - (A - B) / gcd(B, D) > 0)
		return no();
	return ok();
}

int main() {
#ifndef ONLINE_JUDGE
	std::atexit(gettime);
#endif

	int T = read();
	while (T--)
		solve();
}