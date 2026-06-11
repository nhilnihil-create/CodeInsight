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
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}

template<typename T>
void IN(vector<T> &A,int N=-1) {
	if (N == -1) {
		N = A.size();
	}
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
}

template<typename T>
void SO(vector<T> &A,bool F=false) {
	sort(A.begin(), A.end());
	if (F) {
		reverse(A.begin(), A.end());
	}
}
//////////////

void solve() {
	int N, M;
	cin >> N >> M;
	vector<vector<LL>>A(N,vector<LL>(3));
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < 3; ++k) {
			cin >> A[i][k];
		}
	}
	LL ans = 0;
	for (int k = 0; k < (1 << 3); ++k) {
		vector<LL> B(N, 0);
		for (int i = 0; i < N; ++i) {
			LL res = 0;
			int base = 1;
			for (int j = 0; j < 3; ++j,base<<=1) {
				if (k & base) {
					res -= A[i][j];
				}
				else {
					res += A[i][j];
				}
			}
			B[i] = res;
		}
		SO(B);
		LL res = 0;
		for (int i = 0; i < M; ++i) {
			res += B[N - 1 - i];
		}
		chmax(ans, res);
	}
	cout << ans << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
