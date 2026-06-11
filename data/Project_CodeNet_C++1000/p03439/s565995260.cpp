#ifndef __OPTIMIZE_H__
#define __OPTIMIZE_H__

#include <cstdint>
#include <cmath>

/* std::not_fn などに相当するものを自作するほうがいいか？ */

template <class Function>
int64_t findBoundary(Function func, int64_t lower, int64_t upper, bool greater = false);
template <class Function>
double findBoundaryFloat(Function func, double lower, double upper, bool greater = false);
template <class Function>
double findOptimumFloat(Function func, double lower, double upper, bool maximize = false);

/*
// 関数 func : int64_t -> bool に対して
// 二分探索で true と false の境界を(1つ)見つける O(log(upper - lower))
// 探索範囲は [lower, upper)
// デフォルトでは func(i - 1) == true かつ func(i) == false となる i を返す (lower <= i <= upper)
// greater を指定すると真偽を逆にする
*/
template <class Function>
int64_t findBoundary(Function func, int64_t lower, int64_t upper, bool greater) {
	int64_t lo = lower - 1;
	int64_t hi = upper;
	while (hi - lo > 1) {
		int64_t mid = (lo + hi) / 2;
		if (func(mid) == greater) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return hi;
}

/*
// 関数 func : double -> bool に対して
// 二分探索で true から false に変化する境界を(1つ)見つける
// greater を指定すると真偽を逆にする
*/
template <class Function>
double findBoundaryFloat(Function func, double lower, double upper, bool greater) {
	constexpr double precision = 1e-9;
	const int iterations = (int)std::log2((upper - lower) / precision) + 1;
	double lo = lower;
	double hi = upper;
	for (int i = 0; i < iterations; ++i) {
		double mid = (lo + hi) / 2;
		if (func(mid) == greater) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return hi;
}

/*
// 関数 func : double -> double に対して
// 黄金分割探索で極小値をとる点を見つける(maximize を指定すると極大値を探索する)
*/
template <class Function>
double findOptimumFloat(Function func, double lower, double upper, bool maximize) {
	constexpr double precision = 1e-9;
	constexpr double ratio = 1.6180339887498948;
	const int iterations = (int)(std::log((upper - lower) / precision) / std::log(ratio)) + 1;
	
	double lo = lower;
	double hi = upper;
	double mid_lo = (ratio * lo + hi) / (1 + ratio);
	double mid_hi = (lo + ratio * hi) / (1 + ratio);
	double val_lo = func(mid_lo);
	double val_hi = func(mid_hi);
	for (int i = 0; i < iterations; ++i) {
		if ((val_lo > val_hi) == maximize) {
			hi = mid_hi;
			mid_hi = mid_lo;
			mid_lo = (ratio * lo + hi) / (1 + ratio);
			val_hi = val_lo;
			val_lo = func(mid_lo);
		} else {
			lo = mid_lo;
			mid_lo = mid_hi;
			mid_hi = (lo + ratio * hi) / (1 + ratio);
			val_lo = val_hi;
			val_hi = func(mid_hi);
		}
	}
	return hi;
}

#endif

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
#include <array>
#include <random>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using uint = uint32_t;
using LL = int64_t;
using ULL = uint64_t;
using PP = pair<LL, LL>;
template <typename T> using PriorityQ = priority_queue<T, vector<T>, greater<T> >;
#define REP(i, a, n) for(LL i = (a), i##_max_ = (n); i < i##_max_; ++i)
#define REM(i, a, n) for(LL i = (LL)(n) - 1, i##_min_ = (a); i >= i##_min_; --i)
#define FLOAT fixed << setprecision(16)
#define SPEEDUP { cin.tie(NULL); ios::sync_with_stdio(false); }
const int INF = 0x3FFFFFFF;
const LL INFLL = 0x3FFFFFFF3FFFFFFF;
const double INFD = 1.0e+308;
const double EPS = 1.0e-9;

void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
template <class T, class U> istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U> ostream& operator<<(ostream& ost, const pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N> void Fill(T(&dest)[N], const TCompatible& val) { fill(dest, dest + N, val); }
template <class T, class TCompatible, size_t M, size_t N> void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }
template <class T> T Next() { T buf; cin >> buf; return buf; }
istream& Ignore(istream& ist) { string s; ist >> s; return ist; }
bool Inside(int i, int j, int h, int w) { return i >= 0 && i < h && j >= 0 && j < w; }

#ifdef ONLY_MY_ENVIR
#include "IntMod.h"
#include "Accumulator.h"
#include "Algebraic.h"
#include "BinaryMatrix.h"
#include "BinaryTree.h"
#include "Bipartite.h"
#include "BIT.h"
#include "Compressor.h"
#include "Decompositions.h"
#include "DynamicMod.h"
#include "Factorization.h"
#include "FFT.h"
#include "FlowSolver.h"
#include "Graph.h"
#include "GraphUtil.h"
#include "LazySegmentTree.h"
#include "LIS.h"
#include "Math.h"
#include "MathUtil.h"
#include "Matrix.h"
#include "MinCostFlowSolver.h"
#include "MinMax.h"
#include "Numbers.h"
#include "Optimize.h"
#include "Permutation.h"
#include "Polynomial.h"
#include "Position.h"
#include "Range.h"
#include "Rational.h"
#include "SegmentTree.h"
#include "SegmentTree2D.h"
#include "Sets.h"
#include "Shortest.h"
#include "SlidingWindow.h"
#include "SpanningTree.h"
#include "StringSearching.h"
#include "SuffixArray.h"
#include "Tree.h"
#include "UnionFind.h"
#include "VectorUtil.h"
#endif

#ifdef __GNUC__
typedef __int128 LLL;
istream& operator>>(istream& ist, __int128& val) { LL tmp; ist >> tmp; val = tmp; return ist; }
ostream& operator<<(ostream& ost, __int128 val) { LL tmp = val; ost << tmp; return ost; }
#endif

int N;
bool sub(int x) {
	cout << x << endl;
	string s;
	cin >> s;
	if (s == "Vacant") exit(0);
	return (x % 2) ^ (s == "Male");
}

int main() {
	cin >> N;
	cout << 0 << endl;
	string s;
	cin >> s;
	findBoundary(sub, 1, N, s == "Female");
	return 0;
}