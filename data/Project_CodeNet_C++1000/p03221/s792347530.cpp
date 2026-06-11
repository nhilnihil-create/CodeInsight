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
const ll INF = 1e18;
const ll MAX_N = 201010;

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };
ll ans[110][110];

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll>p(m), y(m);
	vector<vector<ll>>town(n + 1);
	rep(i, m) {
		cin >> p[i] >> y[i];
		town[p[i]].push_back(y[i]);
	}
	rep(i, n+1) {
		sort(town[i].begin(), town[i].end());
	}
	rep(i, m) {
		ll res = lower_bound(town[p[i]].begin(), town[p[i]].end(), y[i]) - town[p[i]].begin();
		res++;
		printf("%.6d", p[i]);
		printf("%.6d\n", res);
	}
	return 0;
}
