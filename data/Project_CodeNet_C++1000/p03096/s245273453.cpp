//#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>
//#include <stdio.h>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9+7;
const long long INF = 1e15;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PI;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef unsigned long long ULL;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N;
	cin >> N;
	VI C(N);
	for (int n = 0; n < N; n++)cin >> C[n];
	VLL DP(N, 0);
	VLL DPC(2 * 1e5+1, 0);
	DP[0] = 0;
	LL sum = 0;
	DPC[C[0]] = 1;
	for (int n = 1; n < N; n++) {
		if (C[n] == C[n - 1])continue;
		DP[n] = DPC[C[n]];
		DPC[C[n]] += sum+1;
		DPC[C[n]] %= MOD;
		sum += DP[n];
		sum %= MOD;
	}
	LL ans = 0;
	for (int n = 0; n < N; n++) {
		ans += DP[n];
		ans %= MOD;
	}
	cout << (ans + 1)%MOD << "\n";
	return 0;
}
