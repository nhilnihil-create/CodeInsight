#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) < (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007LL
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589


#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}
pll Dir[8] = { //移動
	{ 0 ,1 },{ -1 ,0 },{ 1 ,0 },{ 0 ,-1 },
	{ 1 ,1 },{ 1 ,-1 },{ -1 ,1 },{ -1 ,-1 }
};

//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define INF 10000000000000000LL

struct Edge {
	int from, to;
	ll w;
};
typedef vector<vector<Edge>> Graph;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll m, ll n)
{
	return m * n / gcd(m, n);
}

ll gettugibaisu(ll from, ll k) {

	ll ret = ((from + k - 1) / k) * k;

	return ret;
}

ll getmaebaisu(ll to, ll k) {

	ll ret = (to / k) * k;

	return ret;
}


signed main(void) {
	int n, m;
	cin >> n >> m;
	Graph g(n);
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].push_back({a,b,1});
		g[b].push_back({ b,a,1 });
	}

	vector<int> wh(n, 2);

	int cou[2] = {};

	function<bool(int, int)> dfs = [&](int c, int pc) {
		wh[c] = 1 - pc;
		cou[wh[c]]++;
		for (auto itr : g[c]) {
			if (wh[itr.to] != 2 && wh[itr.to] == wh[c]) {
				return false;
			}
			if (wh[itr.to] == 2) {
				if (!dfs(itr.to, wh[c])) {
					return false;
				}
			}
		}

		return true;
	};

	bool nibu = dfs(0, 0);

	if (!nibu) {
		cout << (ll)(n - 1)*n / 2  - m<< endl;
	}
	else {
		cout << ((ll)cou[0] * cou[1]) - m << endl;
	}
	return 0;
}

