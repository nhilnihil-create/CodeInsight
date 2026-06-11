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
using namespace std;

typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exout(x) printf("%.10f\n", x)
const double pi = acos(-1.0);
const ll MOD = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 1010;

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

//組み合わせの余りを求める
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };
ll dp[101010];
ll a[1010][1010];

//long longしか使わない
//素数は1より大きい
int main() {
	ll h, w;
	cin >> h >> w;
	vector<pair<ll, ll>>odd;
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}
	vector<tuple<ll, ll, ll, ll>>motion;
	ll ans = 0;
	for (ll i = 0;i < h;i++) {
		for (ll j = 0;j < w-1;++j) {
			if (a[i][j] % 2 != 0) {
				motion.push_back(make_tuple(i, j, i, j + 1));
				a[i][j]--;
				a[i][j + 1]++;
				ans++;
			}
		}
	}
	for (ll i = 0;i < h - 1;++i) {
		if (a[i][w - 1] % 2 == 1) {
			a[i][w - 1]--;
			a[i + 1][w - 1]++;
			motion.push_back(make_tuple(i, w - 1, i + 1, w - 1));
			ans++;
		}
	}
	cout << ans << endl;
	for (ll i = 0;i < motion.size();i++) {
		cout << get<0>(motion[i]) + 1 << " " << get<1>(motion[i]) + 1 << " " << get<2>(motion[i]) + 1 << " " << get<3>(motion[i]) + 1 << endl;
	}
	return 0;
}
