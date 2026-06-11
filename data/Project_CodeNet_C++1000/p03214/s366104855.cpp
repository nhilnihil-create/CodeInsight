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

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef unsigned long long ULL;
//typedef boost::multiprecision::cpp_int bigint;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	LL N;
	cin >> N;
	VLL A(N);
	LL sum = 0;
	for (LL n = 0; n < N; n++) {
		cin >> A[n];
		sum += A[n];
	}
	LL ans = N - 1;
	for (LL n = N - 2; n >= 0; n--) {
		LL crit = abs(sum - A[ans] * N);
		LL comp = abs(sum - A[n] * N);
		if (crit >= comp)ans = n;
	}
	cout << ans << "\n";
	return 0;
}