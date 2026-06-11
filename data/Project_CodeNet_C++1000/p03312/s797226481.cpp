# include <iostream>
# include <algorithm>
#include <array>
# include <cassert>
#include <cctype>
#include <climits>
#include <numeric>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const long long MOD = 1000000000 + 7;//1000000000 + 7 998244353 924844033 1000000000 + 9;
constexpr long long INF = 1LL << 60;//numeric_limits<LL>::max();
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<double, double> Dll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourth; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Rrep(i,mf) for(LL i=mf-1;i>=0;i--)
void YN(bool f) {
	if (f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
void yn(bool f) {
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
struct Edge { LL to, cost; };
struct edge {
	LL from, to, cost;
};
vector<vector<Edge>>g;
vector<edge>ed;
vector<Pll>pv;
set<LL>st;
map<Pll, LL>ma;
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
string str, ss;
bool f[200000];
LL n, m, s, t, h, w, k, q, p, ans, sum[210000], cnt, a[210000], b[210000];
int main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	//2個目 (,i],3個目(i,]
	ans = INF;
	for (int i = 2; i < n - 1; i++) {
		auto it1_ = lower_bound(sum + 1, sum + i + 1, sum[i] / 2) - sum,
			it2_ = lower_bound(sum + i + 1, sum + n, sum[i] + (sum[n] - sum[i]) / 2) - sum;
		if (it1_ == i)it1_--;
		if (it2_ == n)it2_--;
		for (int k = -1; k < 2; k++) {
			for (int l = -1; l < 2; l++) {
				auto it1 = it1_ - k, it2 = it2_ - l;
				if (it1 > 0 && it2 > 0 && it1 < n&&it2 < n) {
					LL p = sum[it1], q = sum[i] - sum[it1], r = sum[it2] - sum[i], s = sum[n] - sum[it2];
					if (p > 0 && q > 0 && r > 0 && s > 0) {
						LL mx = max({ p,q,r,s }), mn = min({ p,q,r,s });
						ans = min(ans, mx - mn);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}