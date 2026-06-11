#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define lowbit(x) x & (-x)
using namespace std;

inline int read() {
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-')	f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

int n, x, a[100007], c[200007], s[100007], l, r;

inline void update(int x, int v) {
	for(; x <= 200006; x += lowbit(x))
		c[x] += v;
}
inline int sum(int x) {
	int res = 0;
	for(; x; x -= lowbit(x))
		res += c[x];
	return res;
}
inline bool check(int x) {
	memset(c, 0, sizeof(c));
	s[0] = 0;
	for(int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + (a[i] >= x ? 1 : -1);
	long long su = 0;
	for(int i = 0; i <= n; ++i) {
		su += sum(s[i] + 100000);
		update(s[i] + 100000, 1);
	} 
	return su >= 1ll * n * (n + 1) / 4;
}

int main() {
	n = read();
	for(int i = 1; i <= n; ++i) {
		a[i] = read();
		r = max(r, a[i]);
	}
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid))	l = mid + 1;
		else	r = mid - 1;
	}
	printf("%d", r);
}