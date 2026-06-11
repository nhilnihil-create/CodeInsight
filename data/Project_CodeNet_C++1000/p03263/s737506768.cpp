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
	int H, W;
	cin >> H >> W;
	vector<vector<int> > A(H, vector<int>(W));
	vector<vector<int> > B(H, vector<int>(W));
	for (int h = 0; h < H; ++h) {
		for (int w = 0; w < W; ++w) {
			cin >> A[h][w];
		}
	}
	B = A;
	int cnt = 0;
	for (int h = 0; h < H; ++h) {
		for (int w = 0; w < W; ++w) {
			if (h + 1 < H) {
				if (A[h][w] & 1) {
					A[h][w]--;
					A[h + 1][w] += 1;
					++cnt;
				}
			}
			else {
				if (w + 1 < W) {
					if (A[h][w] & 1) {
						A[h][w]--;
						A[h][w + 1]++;
						++cnt;
					}
				}
			}
		}
	}
	/*
	int cnt = 0;
	for (int h = 0; h < H; ++h) {
		for (int w = 0; w < W; ++w) {
			if (A[h][w] % 2 == 0) {
				++cnt;
			}
		}
	}
	cout << cnt << endl;
	*/
	cout << cnt << endl;
	for (int h = 0; h < H; ++h) {
		for (int w = 0; w < W; ++w) {
			if (h + 1 < H) {
				if (B[h][w] & 1) {
					B[h][w]--;
					B[h + 1][w] += 1;
					cout << h + 1 << " " << w + 1 << " ";
					cout << h + 1 + 1 << " " << w + 1 << endl;
				}
			}
			else {
				if (w + 1 < W) {
					if (B[h][w] & 1) {
						B[h][w]--;
						B[h][w + 1]++;
						cout << h + 1 << " " << w + 1 << " ";
						cout << h + 1 << " " << w + 1 + 1 << endl;
					}
				}
			}
		}
	}
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
