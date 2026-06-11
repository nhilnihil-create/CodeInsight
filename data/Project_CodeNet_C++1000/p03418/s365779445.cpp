#if defined(__GNUC__)
#include <bits/stdc++.h>
#define __int32 __int32_t
// __GNUC__
#else
#include "bits/stdc++.h"
#endif
using namespace std;

#define int long long

#define itn __int32
#define REP(i, n) for(itn (i) = 0; (i) < (n); ++(i))
#define REP2(i, x, n) for(itn (i) = x; (i) < (n); ++(i))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SORT(x) std::sort(ALL(x))
#define RSORT(x) std::sort(ALL(x), greater<decltype(x)::value_type>())
#define RSORT2(x, T) std::sort(ALL(x), greater<T>())
#define REVERCE(x) std::reverce(ALL(x))
#define ACM(x, y) std::accumulate(ALL(x), y)

#define INT_POW(x, y) [](int a, int b) -> int {int c = a; REP(i, b - 1){c *= a;} return c;}(x, y)
#define INT_POWM(x, y, m) [](int a, int b, int m) -> int {int c = a; REP(i, b - 1){c *= a; c %= m;} return c;}(x, y, m)
#define FCT(x) [](int a) -> int {int r = 1; REP(i, a){r *= i;} return r;}(x)

itn main() {
	std::ios::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	if (!k) {
		cout << n * n;
		return 0;
	}

	int res = 0;

	REP2(i, k + 1, n + 1) {
		res += (i - k) * (n / i) + max(n % i - k + 1, (int)0);
	}

	cout << res;

	return 0;
}
