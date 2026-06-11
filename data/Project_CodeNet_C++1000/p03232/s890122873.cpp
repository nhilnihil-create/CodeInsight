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

struct Combination {
	int mod;
	vector< int64_t > mfact, rfact;
	Combination(int sz, int mod) : mfact(sz + 1), rfact(sz + 1), mod(mod) {
		mfact[0] = 1;
		for (int i = 1; i < mfact.size(); i++) {
			mfact[i] = mfact[i - 1] * i % mod;
		}
		rfact[sz] = inv(mfact[sz]);
		for (int i = sz - 1; i >= 0; i--) {
			rfact[i] = rfact[i + 1] * (i + 1) % mod;
		}
	}
	int64_t fact(int k) const {
		return (mfact[k]);
	}
	int64_t pow(int64_t x, int64_t n) const {
		int64_t ret = 1;
		while (n > 0) {
			if (n & 1) (ret *= x) %= mod;
			(x *= x) %= mod;
			n >>= 1;
		}
		return (ret);
	}
	int64_t inv(int64_t x) const {
		return (pow(x, mod - 2));
	}
};
Combination comb(200000, MOD);
LL n, m, s, t, h, w, k, q, p, ans, sum1[210000],sum2[210000]
, cnt, a[210000], b[210000],fact[210000],rfact[210000];
int main() {
	cin >> n;
	rep(i, n)cin >> a[i];
	rep(i, 200000)fact[i] = comb.mfact[i], rfact[i] = comb.rfact[i];
	rep(i, 200000) {
		sum1[i + 1] = (sum1[i] + rfact[i + 1] * fact[i] % MOD) % MOD;
	}
	// sum1[i]:1/1+1/2~1/i
	// sum2[i]=sum1[1]~sum1[i]
	rep(i, n) {
		LL num = (sum1[i + 1] + sum1[n - i] - 1);
		while (num < 0) {
			num += MOD;
		}
		num %= MOD;
		num *= fact[n];
		num %= MOD;
		ans += num * a[i];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}