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
#define R(i,n) for(int i=0;i<(n);i=i+1)
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
	/*
	LL test=1;
	for (int i = 0; i < 3; ++i) {
		test = (test * 3) % MOD;
	}
	cout << (test * 5*4) % MOD << endl;
	*/
	string S;
	cin >> S;
	int N = S.size();
	vector<vector<LL>>dp(N+1, vector<LL>(3, 0));
	dp[0][0] = 0;
	LL mul = 1;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'A') {
			dp[i + 1][0] = dp[i][0] + mul;
			dp[i + 1][1] = dp[i][1];
			dp[i + 1][2] = dp[i][2];
		}
		else if (S[i] == 'B') {
			dp[i + 1][0] = dp[i][0];
			dp[i + 1][1] = dp[i][1] + dp[i][0];
			dp[i + 1][2] = dp[i][2];
		}
		else if (S[i] == 'C') {
			dp[i + 1][0] = dp[i][0];
			dp[i + 1][1] = dp[i][1];
			dp[i + 1][2] = dp[i][2]+dp[i][1];
		}
		else if (S[i] == '?') {
			dp[i + 1][0] = dp[i][0] * 3 + mul;
			dp[i + 1][1] = dp[i][1] * 3 + dp[i][0];
			dp[i + 1][2] = dp[i][2] * 3 + dp[i][1];
			
			mul = (mul * 3);
		}
		for (int k = 0; k < 3; ++k) {
			dp[i + 1][k] %= MOD;
			mul %= MOD;
		}
	}
	cout << dp[N][2]%MOD << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}