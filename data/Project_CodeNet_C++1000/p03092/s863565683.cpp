#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#include <valarray>
#include <fstream>

using namespace std;
typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> PP;
#define REP(i, a, n) for(LL i = (a), i##_max = (n); i < i##_max; ++i)
#define REM(i, a, n) for(LL i = (LL)(n) - 1, i##min = (a); i >= i##min; --i)
#define ALL(arr) (arr).begin(), (arr).end()
#define FLOAT fixed << setprecision(16)
#define SPEEDUP {cin.tie(NULL); ios::sync_with_stdio(false);}
const int INF = 0x3FFFFFFF;
const LL INFLL = 0x3FFFFFFF3FFFFFFF;
const double INFD = 1.0e+308;
const string INFSTR = "\x7f";
const double EPS = 1.0e-9;

void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
template <class T, class U>
istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U>
ostream& operator<<(ostream& ost, const pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N>
void Fill(T(&dest)[N], const TCompatible& val) { fill(dest, dest + N, val); }
template <class T, class TCompatible, size_t M, size_t N>
void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }
template<class T>
T Compare(T left, T right) { return left > right ? 1 : (left < right ? -1 : 0); }
istream& Ignore(istream& ist) { string s; ist >> s; return ist; }
bool Inside(int i, int j, int h, int w) { return i >= 0 && i < h && j >= 0 && j < w; }
template <class T>
T Next() { T buf; cin >> buf; return buf; }

#ifdef ONLY_MY_ENVIR
#include "IntMod.h"
#include "UnionFind.h"
#include "Graph.h"
#include "Range.h"
#include "Global.h"
#include "FlowSolver.h"
#include "Tree.h"
#include "SuffixArray.h"
#include "Matrix.h"
#include "SegmentTree.h"
#include "SegmentTree2D.h"
#include "BIT.h"
#include "Rational.h"
#include "Position.h"
#include "Factorization.h"
#include "Math.h"
#include "LazySegmentTree.h"
#endif

#ifdef __GNUC__
typedef __int128 LLL;
istream& operator>> (istream& ist, __int128& val) { LL tmp;  ist >> tmp; val = tmp; return ist; }
ostream& operator<< (ostream& ost, __int128 val) { LL tmp = val; ost << tmp; return ost; }
#endif

#if 1234567891
#include <array>
#include <random>
#include <unordered_set>
#include <unordered_map>
template<typename T>
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;
// template <class T>
// auto Is(const T& value) { return [value](const auto& comparand) -> bool { return comparand == value; }; }
#endif

LL N, X, Y;
vector<int> A;
int P[5003][5003];

void pre() {
	REP(i, 1, N + 1) {
		int sum = 0;
		REP(j, 0, N + 1) {
			sum += P[i][j];
			P[i][j] = P[i - 1][j] + sum;
		}
	}
}

int rect(int li, int lj, int ri, int rj) {
	return P[li][lj] - P[li][rj] - P[ri][lj] + P[ri][rj];
}

LL DP[5002];
int main() {
	cin >> N >> X >> Y;
	A.push_back(0);
	REP(i, 0, N) A.push_back(Next<int>());
	A.push_back(N + 1);

	N += 2;
	REP(i, 0, N) {
		++P[i + 1][A[i] + 1];
	}
	pre();

	Fill(DP, INFLL);
	DP[0] = 0;
	REP(i, 1, N) {
		LL mn = INFLL;
		REP(li, 0, i) {
			if (A[li] > A[i]) continue;
			int L = rect(li, A[li], i, N) - 1;
			int R = rect(i, A[li], N, A[i]);

			mn = min(mn, DP[li] + L * X + R * Y);
		}
		DP[i] = mn;
	}
	cout << DP[N - 1] << endl;
	return 0;
}