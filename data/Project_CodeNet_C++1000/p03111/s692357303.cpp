#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <regex>
#include <random>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exout(x) printf("%.10f\n", x)
const double pi = acos(-1.0);
const ll MOD = 1000000007;
const ll INF = 1e10;
const ll MAX_N = 1010;

//組み合わせの余りを求める
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		fac[i] = fac[i - 1] * i;
	}
}

// 二項係数計算
long long COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	if (n > k * 2) {

	}
	return fac[n] / (fac[k] * fac[n - k]);
}

ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };
vector<vector<ll>>tree;
ll cnt[202020];
ll n, A, B, C;
vector<ll>L;

ll dfs(ll depth,ll a,ll b,ll c) {
	if (depth == n) {
		if (!a || !b || !c)return INF;
		return abs(a - A) + abs(b - B) + abs(c - C);
	}
	ll res = dfs(depth + 1, a, b, c);
	res = min(res, dfs(depth + 1, a + L[depth], b, c) + (a ? 10 : 0));
	res = min(res, dfs(depth + 1, a, b + L[depth], c) + (b ? 10 : 0));
	res = min(res, dfs(depth + 1, a, b, c + L[depth]) + (c ? 10 : 0));
	return res;
}

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	cin >> n >> A >> B >> C;
	L.resize(n);
	rep(i, n) {
		cin >> L[i];
	}
	cout << dfs(0, 0, 0, 0) << endl;
	return 0;
}
