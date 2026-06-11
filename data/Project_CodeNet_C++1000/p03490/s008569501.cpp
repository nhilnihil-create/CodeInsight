#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <numeric>
#include <iomanip>
#define M_PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1000000007;
const int MAX_V = 201;
int now = 0;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
struct edge {
	int t;
	edge(int _t) : t(_t) {}
};

ll gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll a[2010];

int ar[10000];
int hr[10000];
int target;
int memo[8002][8002][2];
bool rec(int in,int num,bool var) {

	if (in == 8001) { 
		return memo[in][num][var] = (num == target);
	}

	if (memo[in][num][var] != -1) {
		return memo[in][num][var];
	}

	bool res = false;
	int count = (var ? ar[in] : hr[in]);
	for (int i = 0; i <= count; i++)
	{
		int val = in * i;
		if (num + val > target) break;
		res |= rec(in + 1, num + val, var);
		if (res) { 
			break; 
		}
	}

	return memo[in][num][var] = res;
}
void Solve() {
	
	for (size_t i = 0; i < 8001; i++)
	{
		for (size_t j = 0; j < 8001; j++)
		{
			memo[i][j][0] = -1;
			memo[i][j][1] = -1;
		}
	}
	string s;
	int x, y;
	cin >> s;
	cin >> x >> y;
	int first = 0;
	int varsum = 0;
	int holsum = 0;
	bool ft = false;
	bool var = false;
	int cache = 0;
	s += "T";
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == 'T') {
			if (ft) {
				if (var) {
					hr[cache]++;
					varsum += cache;

				}
				else {
					ar[cache]++;
					holsum += cache;
				}
			}
			ft = true;
			var = !var;
			cache = 0;

			continue;
		}
		if (!ft) {
			first++;
		}
		else {
			cache++;
		}
	}
	int tx = 0;
	if (x < 0) {
		tx = -x + first;
	}
	else {
		tx = x - first;
	}
	if (tx > holsum) {
		cout << "No" << endl;
		return;
	}
	else if((holsum - tx) % 2 != 0){
		cout << "No" << endl;
		return;
	}
	else {
		target = (holsum - tx) / 2;
	}

	bool r = rec(0, 0, true);

	int ty = 0;
	if (y < 0) {
		ty = -y;
	}
	else {
		ty = y;
	}
	if (ty > varsum) {
		cout << "No" << endl;
		return;
	}
	else if ((varsum - ty) % 2 != 0) {
		cout << "No" << endl;
		return;
	}
	else {
		target = (varsum - ty) / 2;
	}

	if (r && rec(0,0,false)) {	
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
}


int main() {
	Solve();
	return 0;
}

