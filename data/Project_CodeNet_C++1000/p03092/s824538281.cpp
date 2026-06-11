#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define fir first
#define sec second
#define tct template<class type>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 5e3, mod = 1e9 + 7;
int n, A, B, p[maxn + 5];
ll f[maxn + 5];

inline void red(int &x) { x += x >> 31 & mod; }
tct inline void cmax(type &x, type y) { x < y ? x = y : 0; }
tct inline void cmin(type &x, type y) { x > y ? x = y : 0; }

int main() {
	scanf("%d %d %d", &n, &A, &B);
	rep(i, 1, n) scanf("%d", &p[i]);
	rep(i, 1, n) {
		ll mn = 1e18;
		rep(j, 1, p[i]) mn = min(mn, f[j]);
		f[p[i]] = mn;
		rep(j, 1, p[i] - 1) f[j] += A;
		rep(j, p[i] + 1, n) f[j] += B;
	}
	ll mn = 1e18;
	rep(i, 1, n) mn = min(mn, f[i]);
	printf("%lld\n", mn);
	return 0;
}