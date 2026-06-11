#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }
 
int dp[70000];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	rep(i, (1 << n)) {
		rep(j, n) {
			rep(k, n) {
				if ((i >> j)&(i >> k) & 1) {
					dp[i] += a[j][k];
				}
			}
		}
		dp[i] /= 2;
	}
	rep(i, (1 << n)) {
		vector<int> vec;
		rep(j, n) {
			if ((i >> j) & 1) {
				vec.pb(j);
			}
		}
		int v = vec.size();
		rep(j, (1 << v)) {
			int c = 0;
			rep(k, v) {
				if ((j >> k) & 1) {
					c += (1 << vec[k]);
				}
			}
			chmax(dp[i], dp[c] + dp[i - c]);
		}
	}
	cout << dp[(1 << n) - 1] << endl;
}