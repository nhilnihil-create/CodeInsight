#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N = 5e3 + 5, inf = 1e18;
int read() {
	int x = 0, f = 1; char ch;
	while(! isdigit(ch = getchar())) (ch == '-') && (f = -f);
	for(x = ch ^ 48; isdigit(ch = getchar()); x = (x << 3) + (x << 1) + (ch ^ 48));
	return x * f;
}
template <class T> T Max(T a, T b) { return a > b ? a : b; }
template <class T> T Min(T a, T b) { return a < b ? a : b; }
int n, L, R, a[N], f[N];
signed main() {
	n = read(); R = read(); L = read();
	for(int i = 1; i <= n; ++ i) a[i] = read(), f[i] = 1e18;
	a[0] = 0; a[n + 1] = n + 1; f[0] = 0; f[n + 1] = 1e18;
	for(int i = 1; i <= n + 1; ++ i) {
		int cl = 0, cr = 0;
		for(int j = i - 1; j >= 0; -- j) {
			if(a[j] < a[i]) f[i] = min(f[i], f[j] + cl * L + cr * R);
			if(a[j] < a[i]) cl ++;
			if(a[j] > a[i]) cr ++;
		}
	}
	printf("%lld\n", f[n + 1]);
	return 0;
}