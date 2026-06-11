#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define reT() int T; scan_d(T); rep(t, 0, T)
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define pw(x) (1ll<<(x))
#define lsn (rt<<1)
#define rsn (rt<<1|1)
#define modadd(a,b) {a+=b;a%=MOD;}
#define modmul(a,b) {a*=b;a%=MOD;}
#define LL long long
#define IN freopen("in", "r", stdin)
#define OUT freopen("out", "w", stdout)
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 210000;

template <typename T>
inline bool scan_d(T &ret) {
	char c;
	int sgn;
	if (c = getchar(), c == EOF) return 0;   //EOF
	while (c != '-' && (c < '0' || c > '9')) {
		if ((c = getchar()) == EOF) return 0;
	}
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	ret *= sgn;
	return 1;
}
template<typename T>
void print(T x) {
	static char s[33], *s1;
	s1 = s;
	if (!x) *s1++ = '0';
	if (x < 0) putchar('-'), x = -x;
	while (x) *s1++ = (x % 10 + '0'), x /= 10;
	while (s1-- != s) putchar(*s1);
}
template<typename T>
void println(T x) {
	print(x);
	putchar('\n');
}

int n;
LL a[N], b[N], am[N], bm[N];
int main() {
	while (scan_d(n)) {
		rep(i, 0, n) scan_d(a[i]);
		rep(i, 0, n) scan_d(b[i]);

		LL res = 0;
		rep(i, 0, 30) {
			int vand = pw(i + 1) - 1;
			rep(i, 0, n) am[i] = a[i] & vand;
			rep(i, 0, n) bm[i] = b[i] & vand;
			sort(am, am + n);
			sort(bm, bm + n);

			int cnt = 0;
			rep(j, 0, n) {
				LL vup = pw(i) * 2 - am[j];
				LL vlow = max(pw(i) - am[j], 0ll);
				cnt += lower_bound(bm, bm + n, vup) - bm;
				cnt -= lower_bound(bm, bm + n, vlow) - bm;

				vup = pw(i) * 4 - am[j];
				vlow = pw(i) * 3 - am[j];
				cnt += lower_bound(bm, bm + n, vup) - bm;
				cnt -= lower_bound(bm, bm + n, vlow) - bm;
			}
			if (cnt & 1) res ^= pw(i);
		}
		println(res);
	}
	return 0;
}
