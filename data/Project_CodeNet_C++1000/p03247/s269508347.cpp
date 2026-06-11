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
Pll pos[210000];
int main() {
	cin >> n;
	rep(i, n) {
		cin >> pos[i].fir >> pos[i].sec;
		if (i)
			if ((pos[i].fir + pos[i].sec+10000000000) % 2 != (pos[i - 1].fir + pos[i - 1].sec + 10000000000) % 2)
				f = 1;
	}

	if (f) {
		cout << -1 << endl;
		return 0;
	}
	vector<LL>v;
	if ((pos[0].fir + pos[0].sec) % 2==0) {
		v.push_back(1);
	}
	rep(i, 37) {
		if ((1LL << i) < 100000000000000)
			v.push_back((1LL << i));
	}
	sort(v.begin(), v.end(), [](LL x, LL y) {return x > y; });
	cout << v.size() << endl;
	rep(i, v.size()) {
		if (i)cout << " ";
		cout << v[i];
	}
	cout << endl;
	rep(i, n) {
		str.clear();
		LL x = pos[i].first + pos[i].second, y = pos[i].first - pos[i].second;
		rep(j, v.size()) {
			if (x >= 0 && y >= 0) {
				str.push_back('R');
				x -= v[j], y -= v[j];
			}
			else if (x >= 0 && y < 0) {
				str.push_back('U');
				x -= v[j], y += v[j];
			}
			else if (x < 0 && y >= 0) {
				str.push_back('D');
				x += v[j], y -= v[j];
			}
			else {
				str.push_back('L');
				x += v[j], y += v[j];
			}
		}
		cout << str << endl;
	}
	return 0;
}