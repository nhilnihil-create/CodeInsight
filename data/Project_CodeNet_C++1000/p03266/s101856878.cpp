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
const int INF = (int)1e9;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9; 
/////////
using namespace::std;
//////////////

LL cal(LL A) {
	LL ans = 0;
	if (A >= 3) {
		ans += A * (A - 1) * (A - 2);
	}
	if (A >= 2) {
		ans += A * (A - 1) * 3;
	}
	ans += A;
	return ans;
}
void solve() {
	int N, K;
	cin >> N >> K;
	LL A = N / K;
	LL ans = 0;
	ans = cal(A);

	if (K % 2 == 0) {
		LL B = N / (K / 2);
		B -= A;
		ans += cal(B);
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
