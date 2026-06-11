#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long lnt;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n; lnt s, mi = INF; bool equ = true;
int main() {
	read(n);
	while (n--) {
		lnt a, b; read(a), read(b);
		s += a, equ &= (a == b);
		if (a > b) mi = min(mi, b);
	}
	if (equ) return puts("0"), 0;
	return printf("%lld\n", s-mi), 0;
}
