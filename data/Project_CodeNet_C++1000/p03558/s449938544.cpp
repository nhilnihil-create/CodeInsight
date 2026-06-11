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

struct vertex
{
	int next;
	int cost;
	bool visit = false;
};

itn main() {
	std::ios::sync_with_stdio(false);

	int k;

	cin >> k;

	vector<vector<vertex>> grp(k);

	REP(i, k) {
		grp[i].push_back(vertex{ (i + 1) % k, 1 });
		grp[i].push_back(vertex{ (i * 10) % k, 0 });
	}

	deque<pair<int , int>> q;

	q.push_front(pair<int, int>(1, 0));

	int res = 1e9;

	while (!q.empty()) {
		auto d = q.front();
		q.pop_front();

		for (auto &v : grp[d.first]) {
			if (!v.visit) {
				if (v.next) {
					if (v.cost) {
						q.push_back(pair<int, int>(v.next, d.second + 1));
					}
					else {
						q.push_front(pair<int, int>(v.next, d.second));
					}
				}
				else {
					if (v.cost) {
						res = min(res, d.second + 2);
					}
					else {
						res = min(res, d.second + 1);
					}
				}
			}
			v.visit = true;
		}
	}

	cout << res;

	return 0;
}
