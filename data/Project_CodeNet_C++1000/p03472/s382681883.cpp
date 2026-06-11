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

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

ll dp[201010][2];
ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };

//long longしか使わない
//素数は1より大きい
int main() {
	ll n, h;
	cin >> n >> h;
	vector<pair<ll, ll>>a(n), b(n);
	rep(i, n) {
		cin >> a[i].first >> a[i].second;
		b[i] = make_pair(a[i].second, a[i].first);
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	ll ans = 0;
	rep(i, n) {
		if (a[0].first <= b[i].first) {
			h -= b[i].first;
			ans++;
		}
		if (h <= 0)break;
	}
	if (h > 0) {
		while (h > 0) {
			ans++;
			h -= a[0].first;
		}
	}
	cout << ans << endl;
	return 0;
}