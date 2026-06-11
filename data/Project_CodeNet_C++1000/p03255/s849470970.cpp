#include <bits/stdc++.h>
#define LL long long
#define db double
using namespace std;
 
const int MAXN = 200200;
const int MAXE = 400400;
const int INF = 0x3f3f3f3f;
 
template<typename T> inline void CheckMax(T &A, T B) {
	A < B ? A = B : A;
}
 
template<typename T> inline void CheckMin(T &A, T B) {
	A > B ? A = B : A;
}
 
template <typename T> inline void read(T &x) {
    int c = getchar();
    bool f = false;
    for (x = 0; !isdigit(c); c = getchar()) {
        if (c == '-') {
            f = true;
        }
    }
    for (; isdigit(c); c = getchar()) {
        x = x * 10 + c - '0';
    }
    if (f) {
        x = -x;
    }
}

int X, a[MAXN], n;
LL sum[MAXN];

LL diff(int l, int r) {
	return sum[r] - sum[l - 1];
}

signed main() {
	read(n), read(X);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (LL) a[i];
	LL ans = (1LL << 61);
	for(int i = 1; i <= n; i++) {
		LL res = (LL)i * X;
		for(int j = n, k = 1; j && res < ans; k++) {
			int pos = max(j - i + 1, 1);
			res += diff(pos, j) * (LL)(k == 1 ? 5 : (k << 1 | 1));
			j = pos - 1;
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans + (LL) n * (LL) X);
	return 0;
}