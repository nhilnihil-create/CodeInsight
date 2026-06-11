#include <bits/stdc++.h>
using namespace std;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, a[1<<18], b[1<<18], c[1<<18];
int main() {
	read(n);
	for (int i = 0; i < (1<<n); i++) read(a[i]);
	for (int i = 0; i < (1<<n); i++)
		for (int j = i; j < (1<<n); j = (j+1)|i)
			c[j] = max(c[j], a[i]+b[j]), b[j] = max(b[j], a[i]);
	for (int i = 0; i < (1<<n); i++) c[i] = max(c[i], c[i-1]);
	for (int i = 1; i < (1<<n); i++) printf("%d\n", c[i]);
	return 0;
}
