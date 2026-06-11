#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL read() {
	LL x = 0, fh = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') fh = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return x * fh;
}
const int N = 1e5 + 10;
int n, i, vis[N];
int main() {
	n = read();
	for (i = 2; ; i++) {
		vis[n] = 1;
		n = (n & 1 ? n * 3 + 1 : n / 2);
		if (vis[n]) break;
	}
	cout << i << '\n';
	return 0;
}