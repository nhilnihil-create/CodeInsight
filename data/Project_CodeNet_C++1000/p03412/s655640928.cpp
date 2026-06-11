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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

signed main(void) {
	int n;

	cin >> n;

	vector<int> a(n), b(n);


	REP(i, n) {
		cin >> a[i];

	}

	REP(i, n) {
		cin >> b[i];
	}

	sort(ALL(a));
	sort(ALL(b));

	int ans = 0;

	REP(i, 29) {
		int cur = 0;
		REP(j, n) {
			cur ^= (n * bitcheck(a[j], i)) % 2;
			cur ^= (n * bitcheck(b[j], i)) % 2;
		}

		int base = pow(2, i);

		vector<int> bb(n);
		REP(j, n) {
			bb[j] = b[j] % base;
		}
		sort(ALL(bb));

		REP(j, n) {
			int ovcou = bb.end() - lower_bound(ALL(bb), base - a[j] % base);

			cur ^= ovcou % 2;
		}

		if(cur)
			bitset(ans, i);
	}

	cout << ans << endl;

	return 0;
}

