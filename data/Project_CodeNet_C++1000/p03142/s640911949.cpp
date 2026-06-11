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


inline LL in() { LL in; scanf("%lld", &in); return in; }
inline void outLL(LL out, bool endl = 1) { printf("%lld%c", out, " \n"[endl]); }

int main() {
	int N = in(), M = in();
	VI deg(N);
	VVI G(N); {
		FOR(i, 0, N - 1 + M) {
			int a = in() - 1, b = in() - 1;
			G[a].push_back(b);
			deg[b]++;
		}
	}
	VI par(N); // +1しとく
	int p = 0;
	FOR(i, 0, N) {
		if (deg[i] == 0)par[i] = 0, p = i;
	}
	queue<int>q;
	q.push(p);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int nx : G[v]) {
			deg[nx]--;
			if (deg[nx] == 0) {
				q.push(nx);
				par[nx] = v+1;
			}
		}
	}
	FOR(i, 0, N) {
		outLL(par[i]);
	}

}