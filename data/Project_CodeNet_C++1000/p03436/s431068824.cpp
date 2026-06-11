#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <stack>
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

int main() {
	ll h, w;
	cin >> h >> w;

	char s[60][60];
	ll dp[60][60];

	ll cnt = 0;

	rep(i, 60)rep(j, 60) s[i][j] = '-';
	rep(i, 60)rep(j, 60) dp[i][j] = mod;
	rep(i, h) {
		rep(j, w) {
			cin >> s[i + 1][j + 1];
			if (s[i + 1][j + 1] == '.') cnt++;
		}
	}

	ll ans;

	if (s[1][1] != s[h][w]) ans = -1;


	dp[1][1] = 0;

	queue<P> p;
	p.push(P(1, 1));
	
	while (p.size()) {
		ll i, j, np;
		i = p.front().first;
		j = p.front().second;
		p.pop();
		rep(k, 4) {
			np = dp[i][j] + 1;
			if (s[i + dx[k]][j + dy[k]] == '.') {
				if (np < dp[i + dx[k]][j + dy[k]]) {
					dp[i + dx[k]][j + dy[k]] = np;
					p.push(P(i + dx[k], j + dy[k]));
				}
			}
		}
	}

	if (dp[h][w] == mod) {
		cout << -1;
	}
	else {
		cout << cnt - dp[h][w] - 1;
	}

	return 0;
}


ll cb(ll a, ll b) {
	ll ans = 1;
	rep(i, b) ans *= (a - i);
	rep(i, b) ans /= (b - i);

	return ans;
}
