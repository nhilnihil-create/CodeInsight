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
bool f;
LL n, m, s, t, h, w, k, q, p, ans, sum, cnt, a[210000], b[210000];
LL gcd(LL a, LL b) {
	if (a < b) gcd(b, a);
	LL r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}
int main() {
	cin >> n;
	vector<LL>v;
	rep(i, n / 4 + 1) {
		v.push_back(i * 6 + 2);
		v.push_back(i * 6 + 3);
		v.push_back(i * 6 + 4);
		v.push_back(i * 6 + 6);
	}
	rep(i, n-1) {
		sum += v[i];
		cout << v[i] << endl;
	}
	v.push_back(INF);
	for (int i = 2; i <= 30000; i++) {
		auto it = lower_bound(v.begin(), v.end(), i) - v.begin();
		if (it < n - 1 && v[it] == i)continue;
		LL gc = gcd((sum + i), i);
		if (gc != 1 && (sum + i) % 6 == 0) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}