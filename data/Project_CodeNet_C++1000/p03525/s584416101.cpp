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
const long long MOD = 1e9 + 7;
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
	VI count(24, 0);
	VI D(N);
	for (int n = 0; n < N; n++) {
		cin >> D[n];
		count[D[n]]++;
		if (D[n] == 0 || count[D[n]] >= 3) {
			cout << 0 << "\n";
			return 0;
		}
	}
	int ans = 0;
	for (int c = 0; c < (1 << N); c++) {
		//0->早いほう、1->遅いほう
		for (int n = 0; n <= 23; n++) count[n] = 0;
		count[0] = 1;
		for (int n = 0; n < N; n++) {
			if ((c & (1 << n)) != 0)count[24 - D[n]]++;
			else count[D[n]]++;
		}
		int t = 0;
		for (; t <= 23; t++) {
			if (count[t] >= 2)break;
		}
		if (t != 24)continue;
		int temp = 0;
		for (int d = 1; d <= 23; d++) {
			for (t = 0; t < 23; t++) {
				if (count[t] == 0)continue;
				int tt = t + d;
				if (tt >= 24)tt -= 24;
				if (count[tt] != 0) {
					temp = d;
					break;
				}
			}
			if (temp != 0)break;
		}
		ans = max(ans, temp);
	}
	cout << ans << "\n";
	return 0;
}