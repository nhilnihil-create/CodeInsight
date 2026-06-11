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
char a[110][110];

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	ll n;
	cin >> n;
	vector<ll>a(n);
	vector<ll>L(n), R(n);
	rep(i, n) {
		cin >> a[i];
	}
	L[0] = a[0], R[n - 1] = a[n - 1];
	rep(i, n - 1) {
		L[i + 1] = gcd(L[i], a[i + 1]);
	}
	for (ll i = n - 1;i >= 1;--i) {
		R[i - 1] = gcd(R[i], a[i - 1]);
	}
	ll ans = 0;
	rep(i, n) {
		if (i == 0)ans = max(R[1], ans);
		else if (i == n - 1)ans = max(ans, L[n - 2]);
		else {
			ll res = gcd(L[i - 1], R[i + 1]);
			ans = max(ans, res);
		}
	}
	cout << ans << endl;
	return 0;
}
