#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
ll dx[] = { 1, 0 , -1,  0 }, dy[] = { 0, 1, 0, -1 };
ll cb(ll a, ll b);
void dfs(ll x, ll y, ll z);
vector<vector<ll>> c(10, vector<ll>(10));
vector<ll> r(10, mod);

int main() {
	ll h, w;
	cin >> h >> w;
	vector<vector<ll>> a(h, vector<ll>(w));

	rep(i, 10) {
		rep(j, 10) {
			cin >> c[i][j];
		}
	}

	rep(i, 10) {
		dfs(i, i, 0);
	}

	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}

	ll ans = 0;

	rep(i, h) {
		rep(j, w) {
			if (a[i][j] != -1) ans += r[a[i][j]];
		}
	}


	cout << ans;

	return 0;
}

void dfs(ll x, ll y, ll z) {
	rep(i, 10) {
		if (r[x] >= c[y][i] + z) {
			if (i == 1)	r[x] = min(r[x], c[y][1] + z);
			else if (i == y) continue;
			else dfs(x, i, c[y][i] + z);
		}
	}
	return;
}


ll cb(ll a, ll b) {
	ll ans = 1;
	rep(i, b) ans *= (a - i);
	rep(i, b) ans /= (b - i);

	return ans;
}

ll gcd(ll a, ll b) {
	if (a % b == 0)return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}