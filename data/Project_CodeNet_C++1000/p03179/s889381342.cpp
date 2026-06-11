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

ll mod = 1000000007;
int dp[3010][3010];
int sum[3010][3010];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		dp[1][i] = 1;
		sum[1][i] = i + 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i - 1] == '<') {
				dp[i + 1][j] = (sum[i][n - 1] - sum[i][j] + mod) % mod;
			}
			else {
				if (i + j < n) dp[i + 1][j] = sum[i][j];
			}
			if (j == 0) {
				sum[i + 1][j] = dp[i + 1][j];
			}
			else {
				sum[i + 1][j] = (sum[i + 1][j - 1] + dp[i + 1][j]) % mod;
			}
		}
	}
	cout << dp[n][0] << endl;
}