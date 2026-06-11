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
long long MOD = 1000000000 + 7; //924844033 1000000000 + 9;
constexpr long long INF = numeric_limits<LL>::max();
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
LL h, w, n, m, k, t, s, p, q, last, first, cnt, sum, ans, a[200020], b[220000],dp[1100][21000];
string str, ss;
bool f[220000];
char c[4000][4000];
int di[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
struct Edge { LL to, cost; };
struct edge {
	LL from, to, cost;
};
vector<vector<Edge>>vec,rvec;
vector<edge>ed;
vector<LL>v;
map<string, LL>ma;
set<LL>st;

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
struct query {
	LL w, s, v;
};
vector<query>qu;
int main() {
	cin >> n;
	rep(i, n) {
		LL x, y, z;
		cin >> x >> y >> z;
		qu.push_back(query{x,y,z});
	}
	//dp[i][j] : i番目までで重さの総和jの場合の最大の価値
	sort(qu.begin(), qu.end(), [](query x, query y) {return min(x.s, y.s - x.w) > min(y.s, x.s - y.w); });
	rep(i, n) {
		rep(j, 20010) {
			if (qu[i].s >= j)
				dp[i + 1][j + qu[i].w] = max(dp[i + 1][j + qu[i].w], dp[i][j] + qu[i].v);
			dp[i + 1][j] = max(dp[i][j],dp[i+1][j]);
		}
	}
	rep(i, 20010)ans = max(ans,dp[n][i]);
	cout << ans << endl;
	return 0;
}
