#define _USE_MATH_DEFINES
#pragma region include

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
#pragma endregion //#include
/////////

#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
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
	int N,K;
	cin >> N >> K;
	vector<LL> X(N), Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	LL ans = LINF;
	for (int x0 = 0; x0 < N; ++x0) {
		for (int x1 = 0; x1 < N; ++x1) {
			for (int y0 = 0; y0 < N; ++y0) {
				for (int y1 = 0; y1 < N; ++y1) {
					int cnt = 0;
					for (int i = 0; i < N; ++i) {
						if (X[x0] <= X[i] && X[i] <= X[x1] &&
							Y[y0] <= Y[i] && Y[i] <= Y[y1]) {
							++cnt;
						}
					}
					if (cnt >= K) {
						LL res = (X[x1] - X[x0]) * (Y[y1] - Y[y0]);
						if (ans > res) {
							ans = res;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
}

#pragma region main
signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
#pragma endregion //main()
