#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
/////////

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

////定数
const int INF = (int)1e9 + 10;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9; 
/////////
using namespace::std;
//////////////

void solve() {
	LL N;
	cin >> N;
	
	vector<int> num(101);
	for (int i = 0; i <= 100; ++i) {
		num[i] = i;
	}
	vector<bool> primeFld(101, true);
	vector<int> prime;
	for (int i = 2; i <= 100; ++i) {
		if (primeFld[i]) {
			prime.push_back(i);
			for (int j = i + i; j <= 100; j += i) {
				primeFld[j] = false;
			}
		}
	}
	int pLen = prime.size();
	vector<int> S(prime.size(), 0);
	for (int i = 1; i <= N; ++i) {
		int temp = i;
		for (int j = 0; j < pLen; ++j) {
			if (temp < prime[j]) {
				break;
			}
			while (temp && temp % prime[j] == 0) {
				S[j]++;
				temp /= prime[j];
			}
		}
	}
	LL A = 0;
	LL B = 0;
	LL C = 0;
	LL D = 0;
	LL E = 0;
	LL F = 0;
	LL G = 0;
	
	for (int i = 0; i < prime.size(); ++i) {
		if (S[i] >= 5-1) {
			++A;
		}
		if (S[i] >= 3-1) {
			++B;
		}
		if (S[i] >= 15 - 1) {
			++C;
		}
		if (S[i] >= 5 - 1) {
			++D;
		}

		if (S[i] >= 25 - 1) {
			E++;
		}
		if (S[i] >= 3-1) {
			F++;
		}

		if (S[i] >= 75-1) {
			G++;
		}
	}
	LL ans = 0;
	ans += A * (A - 1) * (B-2)/2;
	ans += C * (D-1);
	ans += E * (F-1);
	ans += G;
	cout << ans << endl;
	
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
