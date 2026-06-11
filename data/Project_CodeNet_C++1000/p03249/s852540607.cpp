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
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)-form-)
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };


inline int ri() { int in; int y = scanf("%d", &in); return in; }
inline LL rl() { LL in; int y = scanf("%lld", &in); return in; }
inline void oi(int i) { printf("%d\n", i); }
inline void od(double i) { printf("%.9f\n", i); }


int main() {
	int N = ri();
	vector<LL> a(N);
	set<PLL>se;
	for (int i = 0; i < N; ++i) {
		a[i] = rl();
		se.insert(PLL(a[i], i));
	}
	VL sub(N, 1);
	auto NG = []() {
		cout << -1 << endl;
		exit(0);
	};
	vector<vector<int>>G(N);
	while (SZ(se) > 1) {
		auto it = se.end();
		--it;
		PLL a = *it;
		se.erase(it);
		LL sa = a.first;
		int v = a.second;
		DD(de(sa, v));
		LL parval = sa + 2 * sub[v] - N;
		auto parnode = se.lower_bound(PLL(parval, 0));
		if (parnode->first != parval)NG();
		int par = parnode->second;
		sub[par] += sub[v];
		G[par].push_back(v);
	}

	function<LL(int)> f = [&](int v) {
		LL ret = 0;
		for (auto nx : G[v]) {
			ret += f(nx) + sub[nx];
		}
		return ret;
	};
	LL res = f(se.begin()->second);
	if (res != se.begin()->first)NG();
	FOR(i, 0, N) {
		for (auto nx : G[i]) {
			printf("%d %d\n", i + 1, nx + 1);
		}
	}

}