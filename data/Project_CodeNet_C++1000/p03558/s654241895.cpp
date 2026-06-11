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
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
long long MOD = 1000000000 + 7;
constexpr long long INF = std::numeric_limits<LL>::max();
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Mfor(i,mf) for(LL i=mf-1;i>=0;i--)
LL h, w, n, m, k, t, s, q, last, cnt, sum[1000000], ans, dp[110000];
Pll a[200000], b[2000000];
string str, ss, dd;
bool f[2000][2000],ff;
char c;
int di[4][2] = { { 0,1 },{ 1,0 },{ -1,0 } ,{ 0,-1 } };
struct Edge { LL to, cost; };
vector<Edge>vec[10000];
vector<Pll>v;
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
int main() {
	cin >> n;
	ans = n;
	queue<Pll>qu;
	qu.push(Pll(1,1));
	rep(i, 110000)dp[i] = INF;
	while (!qu.empty()) {
		Pll num = qu.front();
		qu.pop();
		if (dp[num.fir] <= num.second)
			continue;
		dp[num.fir] = num.sec;
		if (ans <= num.second)
			continue;
		if (num.first == 0) {
			ans = min(ans, num.second);
		}
		else {
			qu.push(Pll((num.first * 10) % n, num.second));
			qu.push(Pll((num.first + 1) % n, num.second + 1));
		}
	}
	cout << ans << endl;
	return 0;
}