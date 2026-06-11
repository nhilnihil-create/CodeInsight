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
	LL N, K;
	cin >> N >> K;
	VLL A(N);
	cin >> A[0];
	for (LL n = 1; n < N; n++) {
		cin >> A[n];
		A[n] += A[n - 1];
	}
	VLL B;
	for (LL e = 0; e < N; e++) {
		B.push_back(A[e]);
		for (LL s = 0; s < e; s++) {
			B.push_back(A[e] - A[s]);
		}
	}
	sort(B.begin(), B.end(), [](LL a, LL b) {
		return a > b;
	});
	LL ans = 0;
	N = B.size();
	for (LL ind = 40; ind >= 0; ind--) {
		if (B[K - 1] >= ((LL)1 << ind)) {
			ans += (LL)1 << ind;
			LL s = K - 1, e = N;
			//B[s] >= 2^ind > B[e]
			while (e - s > 1) {
				LL m = (e + s) / 2;
				if (B[m] >= ((LL)1 << ind))s = m;
				else e = m;
			}
			N = e;
		}
		for (LL n = 0; n < N;n++) {
			LL& b = B[n];
			b = b & (((LL)1 << ind) - 1);
		}
		sort(B.begin(), B.begin()+N, [](LL a, LL b) {
			return a > b;
		});
	}
	cout << ans << "\n";
	return 0;
}