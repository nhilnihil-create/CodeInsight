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
	ll n;
	cin >> n;
	vector<string>s(n);
	ll ans = 0;
	ll b = 0;
	ll a = 0;
	ll c = 0;
	rep(i, n) {
		cin >> s[i];
		ll k = s[i].length();
		rep(j, k-1) {
			if (s[i][j] == 'A' && s[i][j + 1] == 'B')ans++;
		}
		if (s[i][0] == 'B')b++;
		if (s[i][k - 1] == 'A')a++;
		if (s[i][0] == 'B' && s[i][k - 1] == 'A')c++;
	}
	ll res = min(a, b);
	ans += res;
	if (a == b && b == c&&a!=0)ans--;
	cout << ans << endl;
	return 0;
}