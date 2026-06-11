#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = INT_MAX / 2;
const ll  inf = LLONG_MAX / 2;
const int mod = 1000000007;
const int MAX_N = 101010;
const long double PI = acos(-1);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int n;
	cin >> n;

	vector<vector<int>> a(2, vector<int>(n));
	rep(i, 2) {
		rep(j, n) {
			cin >> a[i][j];
		}
	}

	vector<vector<int>> dp(2, vector<int>(n, 0));
	dp[0][0] = a[0][0];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) chmax(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
			if (j < n - 1) chmax(dp[i][j + 1], dp[i][j] + a[i][j + 1]);
		}
	}

	out(dp[1][n - 1]);

	return 0;
}