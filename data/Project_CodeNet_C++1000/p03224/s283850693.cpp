#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <cassert>
#include <unordered_set>
#include <chrono>
#include <bitset>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int

#include <nmmintrin.h>
#ifdef _MSC_VER

#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

struct Edge {
	int from, to, s;
};

signed main() {

	int n;
	cin >> n;

	int ok[100001] = {};

	rep(i, 1, 500) {
		if ((i * (i - 1)) / 2 > 100000) break;
		ok[(i * (i - 1)) / 2] = i;
	}

	if (ok[n] == 0) {
		cout << "No" << endl;
		return 0;
	}

	vector<vector<int>> g(ok[n],vector<int>(ok[n]));

	int edc = 0;

	REP(i, ok[n]) {
		REP(j, ok[n]) {
			if (i <= j) break;

			edc++;
			g[i][j] = edc;
			g[j][i] = edc;

		}
	}

	printf("Yes\n%d\n", ok[n]);
	REP(i, ok[n]) {
		printf("%d", ok[n] - 1);
		REP(j, ok[n]) {
			if (g[i][j] == 0) continue;
			printf(" %d", g[i][j]);
		}
		printf("\n");
	}

	return 0;
}