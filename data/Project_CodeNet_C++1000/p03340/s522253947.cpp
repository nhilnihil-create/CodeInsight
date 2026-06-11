#include <bits/stdc++.h>
#define gc() getchar() 
#define LL long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define _rep(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 2e5 + 5;
int n, a[N];

inline int read() {
	int x = 0;
	char ch = gc();
	while (!isdigit(ch)) ch = gc();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
	return x; 
}

int main() {
	ios::sync_with_stdio(false);
	n = read();
	rep(i, 1, n) a[i] = read();
	LL ans = 0;
	for (int i = 1, l = 1, r = 1, cur = 0; i <= n; ++i) {
		for (; !(cur & a[r]) && r <= n;) cur |= a[r++], ans += r - l;
		cur ^= a[l++];
	}
	cout << ans << endl;
	return 0;
}