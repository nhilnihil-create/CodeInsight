#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  __MAKE_TIME__  Problem: __PROBLEM__ / Link: __CONTEST_URL__  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	vector<PLL>anss;

	LL mx = *max_element(ALL(a));
	LL mn = *min_element(ALL(a));
	bool to_plus = abs(mx) > abs(mn);
	int mxid; {
		if (to_plus) {
			mxid = max_element(ALL(a)) - a.begin();
		}
		else {
			mxid = min_element(ALL(a)) - a.begin();
		}
	}
	FOR(i, 0, N) { // 正規化
		if (mxid == i)continue;
		anss.push_back(PLL(mxid, i));
	}
	if (!to_plus) {
		FORR(i, N - 1, 0) {
			anss.push_back(PLL(i, i - 1));
		}
	}
	else {
		FOR(i, 0, N - 1) {
			anss.push_back(PLL(i, i + 1));
		}
	}

	cout << SZ(anss) << endl;
	for (auto it : anss) {
		cout << it.first + 1 << " " << it.second + 1 << endl;
	}

	return 0;
}
