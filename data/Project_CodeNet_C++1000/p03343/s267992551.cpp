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
	int N, K, Q;
	cin >> N >> K >> Q;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = INF;
	vector<int> temp(N);//候補
	vector<int> temp2(N);//候補候補
	for (int i = 0; i < N; ++i) {
		int X = A[i];
		int num = 0;//選択候補確定
		int cnt = 0;
		/*
		数列分解して、除ける最小値候補を選択
		*/
		for (int j = 0; j < N; ++j) {
			if (A[j] >= X) {
				temp2[cnt] = A[j];
				++cnt;
			}
			else if(A[j] < X ){
				int ter = cnt - K +1;
				if(ter>0){
					sort(temp2.begin(),temp2.begin()+cnt);
					for (int k = 0; k < ter; ++k) {
						temp[num] = temp2[k];
						++num;
					}
				}
				cnt = 0;
			}
		}
		if (cnt) {
			int ter = cnt - K + 1;
			if (ter > 0) {
				sort(temp2.begin(), temp2.begin() + cnt);
				for (int k = 0; k < ter; ++k) {
					temp[num] = temp2[k];
					++num;
				}
			}
			cnt = 0;
		}

		if (num >= Q) {//Q個以上取り除ける候補がある。
			sort(temp.begin(), temp.begin() + num);
			ans = min(ans, temp[Q - 1] - temp[0]);
		}
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
