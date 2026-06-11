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
#include "Union_Find.h"
#include "Graph.h"
#include "Range.h"
#include "Global.h"
#include "Flow_Solver.h"
#include "Tree.h"
#include "Suffix_Array.h"
#include "Geometry.h"
#include "Matrix.h"
#include "Segment_Tree.h"
#include "BIT.h"
#include "Rational.h"
#include "Position.h"
#include "Factorization.h"
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

LL N, X;
LL A[200001];

LL sub(int k) {
	LL sum = 0;
	LL cnt = 0;
	for (int i = N; i >= 0; i -= k) {
		LL r = i;
		LL l = max(0, i - k);

		sum += (A[r] - A[l]) * (cnt == 0 ? 5 : cnt * 2 + 3);
		++cnt;
		if (sum >= INFLL / 2) return INFLL;
	}
	return sum + X * (N + k);
}

int main() {
	cin >> N >> X;
	REP(i, 0, N) {
		cin >> A[i + 1];
	}

	partial_sum(A, A + N + 1, A);
	
	LL mn = INFLL;
	REP(k, 1, N + 1) {
		mn = min(mn, sub(k));
	}
	cout << mn << endl;
	return 0;
}