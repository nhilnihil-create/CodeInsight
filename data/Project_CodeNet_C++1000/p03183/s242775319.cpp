#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define N 30010
#define ll long long
using namespace std;

struct info {
	int w, s, v;
	friend bool operator<(info a, info b) {
		return a.w + a.s < b.w + b.s;
	}
} A[N];
int n;
ll f[N * 10];

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
#define cmax(a,b) (a<b)?a=b:1
int main() {
	n = read();
	for (int i = 1; i <= n; ++i)A[i].w = read(), A[i].s = read(), A[i].v = read();
	sort(A + 1, A + n + 1);
	for (int i = 1; i <= n; ++i)for (int j = A[i].s; j >= 0; --j)cmax(f[j + A[i].w], f[j] + A[i].v);
	ll Ans = 0;
	for (int i = 0; i <= 30000; ++i)Ans = max(Ans, f[i]);
	printf("%lld\n", Ans);
	return 0;
}
