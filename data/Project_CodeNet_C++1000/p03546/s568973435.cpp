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

ll c[20][20];
ll math[220][220];
ll number[11];
ll dp[20][20];

//long longしか使わない
//素数は1より大きい
int main() {
	ll h, w;
	cin >> h >> w;
	rep(i, 10) {
		rep(j, 10) {
			cin >> c[i][j];
		}
	}
	rep(i, 10) {
		rep(j, 10) {
			if (j == 1)continue;
			rep(k, 10) {
				if (j == k)continue;
				c[j][k] = min(c[j][k], c[j][i] + c[i][k]);
			}
		}
	}
	ll ans = 0;
	rep(i, h) {
		rep(j, w) {
			cin >> math[i][j];
			if (math[i][j] != 1 && math[i][j] != -1)ans += c[math[i][j]][1];
		}
	}
	cout << ans << endl;
	return 0;
}
