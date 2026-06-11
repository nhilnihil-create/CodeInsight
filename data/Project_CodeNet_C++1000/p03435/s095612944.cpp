// type a
//a...いけそう
//b...自信がない
//c...お試し
#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>
#include <array>
// ===============================================================
//using系
#pragma region header
using namespace std;
using ll = long long;
using lint = long long;
using ld = long double;
using ulint = unsigned long long;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr lint mod = 1000000007;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define
#define INF (lint)10000000000000000
#define mod = (lint)1000000007;
#pragma endregion

vector<vector<int>> d(3, vector<int>(3));
void input() {
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++)
			cin >> d[i][j];
	return;
}
void solve() {
	int a1, a2, a3, b1, b2, b3;
	a1 = 0;
	b1 = d[0][0] - a1;
	b2 = d[0][1] - a1;
	b3 = d[0][2] - a1;
	a2 = d[1][0] - b1;
	a3 = d[2][0] - b1;
	if (a1 + b1 != d[0][0]) { puts("No"); return; }
	if (a2 + b1 != d[1][0]) { puts("No"); return; }
	if (a3 + b1 != d[2][0]) { puts("No"); return; }
	if (a1 + b2 != d[0][1]) { puts("No"); return; }
	if (a2 + b2 != d[1][1]) { puts("No"); return; }
	if (a3 + b2 != d[2][1]) { puts("No"); return; }
	if (a1 + b3 != d[0][2]) { puts("No"); return; }
	if (a2 + b3 != d[1][2]) { puts("No"); return; }
	if (a3 + b3 != d[2][2]) { puts("No"); return; }
	puts("Yes");
	return;
}

int main(void) {
	input();
	solve();

	return 0;
}