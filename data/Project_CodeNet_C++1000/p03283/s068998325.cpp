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
#define R(i,n) for(int i=0;i<(n);++i)
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
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<vector<int>> A(N+1, vector<int>(N+1, 0));
	for (int i = 0; i < M; ++i) {
		int L, R;
		cin >> L >> R;
		A[L][R]++;
		/*
		A[L - 1][L - 1]--;
		A[L - 1][R]++;
		A[L - 1][R]--;
		A[R][R]++;*/
	}
	for (int h = 1; h <= N; ++h) {
		for (int w = 1; w <= N; ++w) {
			A[h][w] += A[h][w - 1];
		}
	}
	for (int w = 1; w <= N; ++w) {
		for (int h = 1; h <= N; ++h) {
			A[h][w] += A[h-1][w];
		}
	}
	while (Q--) {
		int p, q;
		cin >> p >> q;
		int res = A[q][q]-A[q][p-1]-A[p-1][q]+A[p-1][p-1];
		cout << res << endl;
	}
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}