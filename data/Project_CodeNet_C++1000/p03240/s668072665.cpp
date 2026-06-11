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
void chmax(LL& a, LL b) {
	a = max(a, b);
}
void chmin(LL& a, LL b) {
	a = min(a, b);
}
//////////////

LL cal(LL Cx, LL Cy, LL X, LL Y, LL Hxy) {
	LL len = abs(Cx - X) + abs(Cy - Y);
	LL ans = Hxy + len;
	return ans;
}

LL f(LL Cx, LL Cy, LL H, LL X, LL Y) {
	LL ret = max(H - abs(Cx - X) - abs(Cy - Y), (LL)0);
	return ret;
}
void solve() {
	int N;
	cin >> N;
	vector < LL> X(N), Y(N), H(N);

	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i] >> H[i];
	}

	for (int Cx = 0; Cx <= 100; ++Cx) {
		for (int Cy = 0; Cy <= 100; ++Cy) {
			LL now = -1;
			bool flag = true;
			for (int i = 0; i < N; ++i) {
				if (H[i] == 0)continue;

				LL res = cal(Cx, Cy, X[i], Y[i], H[i]);
				if (now == -1) {
					now = res;
				}
				else if (now != res) {
					flag = false;
					break;
				}
			}
			if (flag) {
				bool OK = true;
				for (int i = 0; i < N; ++i) {
					LL res = f(Cx, Cy, now, X[i], Y[i]);
					if (res != H[i]) {
						OK = false;
						break;
					}
				}
				if (OK) {
					cout << Cx << " " << Cy << " " << now << endl;
					return;
				}
			}
		}
	}
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
