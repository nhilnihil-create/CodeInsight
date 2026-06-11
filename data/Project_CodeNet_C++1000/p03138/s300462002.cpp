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
/*
4 4
4 0 0 0
*/

vector<pair<LL,int> > make(LL K) {
	vector<pair<LL, int>> ans;
	LL bit = 1;
	for (int i = 0; K; ++i) {
		if (K & bit) {
			K ^= bit;
			ans.push_back(pair<LL, int>(K, i));
		}
		bit <<= 1;
	}
	return ans;
}
void solve() {
	LL N, K;
	cin >> N >> K;
	vector<int> B(60);
	vector<LL> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		LL ter = A[i];
		for (int j = 0; j < 60; ++j) {
			B[j] += (ter & 1);
			ter /= 2;
		}
	}

	vector<LL> ans;
	ans.push_back(K);

	vector<pair<LL,int>> X = make(K);
	int len = X.size();
	LL base = (LL)1 << 59;
	for(int x=0;x<len;++x){
		LL now = X[x].first;
		base = (LL)1 << max(0, X[x].second - 1);

		for (int i = X[x].second-1; i >= 0; --i) {
			LL bit1 = B[i];
			LL bit0 = N - B[i];
			LL H = N / 2;
			if (bit0 > H) {
				now += base;
			}
			base >>= 1;
		}
		ans.push_back(now);
	}
	LL ans2 = 0;
	for(int a=0;a<ans.size();++a){
		LL res = 0;
		for (int i = 0; i < N; ++i) {
			res += (ans[a] ^ A[i]);
		}
		chmax(ans2, res);
	}
	cout << ans2 << endl;
}

signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
