#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
	int x = 0, fh = 1;
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
int i, a[4];
int main() {
	for (i = 1; i <= 3; i++) a[i] = read();
	sort(a + 1, a + 1 + 3);
	cout << a[1] * a[2] / 2;
	return 0;
}