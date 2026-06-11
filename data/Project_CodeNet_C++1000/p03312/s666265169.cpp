#include <bits/stdc++.h>
#define MAX_N 200000
using namespace std;
typedef long long lnt;
const lnt INF = 0x3f3f3f3f3f3f3f3fLL;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n; lnt s[MAX_N+5], mi, mx, ans = INF;
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(s[i]), s[i] += s[i-1];
	for (int l = 1, p = 2, r = 3; p < n; p++) {
		mi = INF;
		for (; l < p; l++)
			if (abs(s[l]-(s[p]-s[l])) < mi)
				mi = abs(s[l]-(s[p]-s[l]));
			else break;
		mi = INF;
		for (r = max(r, p+1); r <= n; r++)
			if (abs((s[r]-s[p])-(s[n]-s[r])) < mi)
				mi = abs((s[r]-s[p])-(s[n]-s[r]));
			else break;
		l--, r--;
		mi = min(min(s[l], s[p]-s[l]), min(s[r]-s[p], s[n]-s[r]));
		mx = max(max(s[l], s[p]-s[l]), max(s[r]-s[p], s[n]-s[r]));
		ans = min(ans, mx-mi);
	}
	return printf("%lld\n", ans), 0;
}
