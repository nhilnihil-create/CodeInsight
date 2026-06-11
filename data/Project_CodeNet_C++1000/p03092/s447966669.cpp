#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <tuple>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
//ll mod = 1000000007;
//ll mod = 998244353;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	vector<ll> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, LINF));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j < p[i]) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a);
				dp[i + 1][p[i]] = min(dp[i + 1][p[i]], dp[i][j]);
			}
			if (j > p[i]) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b);
			}
		}
	}
	ll ans = LINF;
	for (int i = 0; i <= n; i++) ans = min(ans, dp[n][i]);
	cout << ans << endl;
}