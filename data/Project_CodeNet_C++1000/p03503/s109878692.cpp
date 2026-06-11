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
long long  bitcount64(long long bits)
{
	bits = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);
	bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);
	bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);
	bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);
	bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);
	return (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);
}

void solve() {
	int N;
	cin >> N;
	vector<int> M(N);
	for (int i = 0; i < N; ++i) {
		int s = 0;
		int k;
		for (int j = 0; j < 10; ++j) {
			cin >> k;
			s |= (k << j);
		}
		M[i] = s;
	}
	vector< vector<LL> > P(N, vector<LL>(11));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 11; ++j) {
			cin >> P[i][j];
		}
	}
	LL ans = -LINF;
	for (int s = 1; s < (1 << 10); ++s) {
		LL res = 0;
		for (int i = 0; i < N; ++i) {
			int ter = s & M[i];
			int c = bitcount64(ter);
			res += P[i][c];
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