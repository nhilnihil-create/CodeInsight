#include <bits/stdc++.h>
using namespace std;
typedef long long lnt;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
lnt S(lnt x) {
	lnt ret = 0;
	for (; x; x /= 10)
		ret += x%10;
	return ret;
}
bool chk(lnt x, lnt y) {return x*S(y) <= y*S(x);}
int main() {
	int n, m = 0; read(n);
	for (lnt x = 1, d = 1; m < n; x += d)
		if (chk(x, x+d))
			printf("%lld\n", x), m++;
		else x -= d, d *= 10;
	return 0;
}
