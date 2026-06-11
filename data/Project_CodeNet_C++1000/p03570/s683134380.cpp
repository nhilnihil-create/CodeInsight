#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <limits>
#include <numeric>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> PP;
#define REP(i,a,n) for(int i = (a); i < (int)(n); ++i)
#define REPM(i,n,a) for(int i = ((n) - 1); i >= (a); --i)
#define FLOAT setprecision(16)
#define SPEEDUP {cin.tie(0); ios::sync_with_stdio(false);}
#define INSIDE(i,j,H,W) ((i) >= 0 && (i) < (H) && (j) >= 0 && (j) < (W))
#define YesNo(b) (b ? "Yes" : "No")
#define YESNO(b) (b ? "YES" : "NO")
const int INF = 0x3FFFFFFF;
const LL INFLL = 0x3FFFFFFF3FFFFFFF;
const double INFD = 1.0e+308;
const double EPS = 1.0e-9;

template <class T, class U>
istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U>
ostream& operator<<(ostream& ost, const pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N>
void Fill(T(&dest)[N], const TCompatible& val) { fill(begin(dest), end(dest), val); }
template <class T, class TCompatible, size_t M, size_t N>
void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }

// all_of
// partial_sum, adjacent_difference

#if _DEBUG
#include "IntMod.h"
#include "Union_Find.h"
#include "Graph.h"
#include "Range.h"
#include "Global.h"
#include "Flow_Solver.h"
#include "Tree.h"
#include "Suffix_Array.h"
#endif

#if 1234567891
#include <array>
#include <unordered_set>
#include <unordered_map>
template<typename T>
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;	// コスト小を優先
#endif

string s;
int H[200001];	// 累積和
int MIN[1 << 26];
int main() {
	cin >> s;
	int N = s.size();
	REP(i, 0, N) {
		H[i + 1] = H[i] ^ (1 << (s[i] - 'a'));
	}

	if (H[N] == H[0]) {
		cout << 1 << endl;
		return 0;
	}

	Fill(MIN, INF);
	MIN[0] = 0;
	REP(i, 1, N + 1) {
		int dp = MIN[H[i]];
		REP(c, 0, 26) {
			int ref = (H[i] ^ (1 << c));
			dp = min(dp, MIN[ref]);
		}
		MIN[H[i]] = min(MIN[H[i]], dp + 1);
	}

	cout << MIN[H[N]] << endl;
	return 0;
}
