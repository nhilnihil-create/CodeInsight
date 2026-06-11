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

ll dp[101010][110];
ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };

//long longしか使わない
//素数は1より大きい
int main() {
	ll n;
	cin >> n;
	vector<ll>b(n);
	vector<ll>flag(n);
	rep(i, n) {
		cin >> b[i];
		b[i]--;
		if (b[i] > i) {
			cout << -1 << endl;
			return 0;
		}
	}
	vector<ll>ans;
	rep(j, n) {
		ll m = b.size();
		for (ll i = m - 1;i >= 0;--i) {
			if (b[i] == i) {
				ans.push_back(b[i] + 1);
				b.erase(b.begin() + i);
				break;
			}
		}
	}

	reverse(ans.begin(), ans.end());
	rep(i, n) {
		cout << ans[i] << endl;
	}
	return 0;
}