#include <bits/stdc++.h>
using namespace std;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, m, l;
int x[65], y[65], z[65];
void addedge(int u, int v, int c) {
	m++, x[m] = u+1, y[m] = v+1, z[m] = c;
}
int main() {
	read(l);
	for (; (1<<n) <= l; n++) ; n--;
	for (int i = 0; i < n; i++)
		addedge(i, i+1, 0), addedge(i, i+1, 1<<i);
	int base = 1<<n;
	for (int i = n-1; ~i; i--) if (l>>i&1)
		addedge(i, n, base), base += 1<<i;
	printf("%d %d\n", n+1, m);
	for (int i = 1; i <= m; i++)
		printf("%d %d %d\n", x[i], y[i], z[i]);
	return 0;
}