#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T>
inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar()) f ^= c == '-';
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
    x = f ? -x : x;
}
template <class T>
inline void write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T y = 10, len = 1;
    while (y <= x) { y *= 10; ++len; }
    while (len--) { y /= 10; putchar(x / y + 48); x %= y; }
}

const int MAXN = 2010;

bitset <MAXN * MAXN> f;

int n, x, sum;

int main() {
	read(n);
	f[0] = 1;
	for (int i = 1; i <= n; ++i) { read(x); f |= f << x; sum += x; }
	for (int i = (sum + 1) >> 1; i <= sum; ++i) if (f[i]) { printf("%d\n", i); return 0; }
	return 0;
}