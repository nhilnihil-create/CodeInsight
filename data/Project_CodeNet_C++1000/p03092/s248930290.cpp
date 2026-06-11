/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e3 + 10;
const ll inf = 1e15 + 42;

int p[N];
ll dp[N][N];

int main() {
	fast_cin();
	int n; ll a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (dp[i][j] == inf) {
				continue;
			}
			if (j >= p[i + 1]) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b);
			} else {
				dp[i + 1][p[i + 1]] = min(dp[i + 1][p[i + 1]], dp[i][j]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a);
			}
		}
	}
	ll ans = inf;
	for (int j = 0; j <= n; ++j) {
		ans = min(ans, dp[n][j]);
	}
	cout << ans << endl;
}