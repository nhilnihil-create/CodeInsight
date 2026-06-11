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
#define chmax(a,b) a = max(a,b);
#define chmin(a,b) a = min(a,b);

struct Edge {
	ll from, to;
	ll w;
};


int memo[1 << 18 + 1][2] = {};
int n;
vector<int> a;

void func(int k) {
	if (memo[k][0] != n) return;
	memo[k][0] = k;
	REP(i, 20) {
		if (bitcheck(k, i)) {
			int nex = k & (~(1 << i));
			func(nex);
			pii buf[4] = { {a[memo[k][0]],memo[k][0]},{a[memo[k][1]],memo[k][1]},{a[memo[nex][0]],memo[nex][0]},{a[memo[nex][1]],memo[nex][1]} };
			sort(buf, buf + 4, greater<pii>());
			unique(buf, buf + 4);
			memo[k][0] = buf[0].second;
			memo[k][1] = buf[1].second;
		}
	}
}

signed main(void) {
	cin >> n;
	n = pow(2, n);
	Fill(memo, n);
	a.resize(n);
	REP(i, n)
		cin >> a[i];

	a.push_back(0);

	int Max = 0;

	rep(i, 1, n) {
		func(i);
		chmax(Max, a[memo[i][1]] + a[memo[i][0]]);
		printf("%d\n", Max);
	}



	return 0;
}