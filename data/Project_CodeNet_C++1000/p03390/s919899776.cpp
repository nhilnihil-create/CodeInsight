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
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = std::numeric_limits<long long>::max();
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
LL h, w, n, m, k, s, t, q, sum, last, cnt, ans, a[100000];
string str,ss;
bool f;
char c[10000][10000];
struct Edge { LL to,cost; };
vector<Edge>vec[1000];
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
	rep(i, n) {
		LL x, y;
		cin >> x >> y;
		LL l = 0, r = 10000000000;
		while (r - l > 1) {
			LL mid = (l + r) / 2;
			if (x*y > mid * mid)l = mid;
			else r = mid;
		}
		LL now = l; l = 0, r = 10000000000;
		while (r - l > 1) {
			LL mid = (l + r) / 2;
			if (x*y > mid * now)l = mid;
			else r = mid;
		}
		if (x == 1 && y == 1)
			cout << 0 << endl;
		else
			cout << l - now - (x*y == (LL)sqrt(x*y)*(LL)sqrt(x*y) && x != y ? 1 : 0) + now * 2 - 2 << endl;
	}
	return 0;
}