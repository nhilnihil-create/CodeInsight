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
	int from, to;
};

int main() {
	string str;
	cin >> str;
	int x, y;
	cin >> x >> y;

	vector<int> xm, ym;

	int cc = 0, ct = 0;
	for (auto itr : str) {
		if (itr == 'T') {
			if (ct) ym.push_back(cc); 
			else xm.push_back(cc);
			ct = 1 - ct;
			cc = 0;
		}
		else {
			cc++;
		}
	}
	if (ct) ym.push_back(cc);
	else xm.push_back(cc);

	auto func = [&](vector<int> &siji, int tar, bool ix) {
		int dp[2][17001] = {};
		dp[0][8500] = 1;
		REP(i, siji.size()) {
			REP(j, 17001)
				dp[1 - i % 2][j] = 0;
			REP(j, 17001) {
				if (dp[i%2][j]) {
					dp[1 - i % 2][j + siji[i]] = 1;
					if (ix && i == 0) continue;
					dp[1 - i % 2][j - siji[i]] = 1;
				}
			}
		}
		return dp[siji.size()%2][tar + 8500];
	};

	if (func(xm, x,1) && func(ym, y,0)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}