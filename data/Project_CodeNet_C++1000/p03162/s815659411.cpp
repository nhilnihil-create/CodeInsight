//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define bit(i) (1<<(i))
#define set(mask,i) (mask |= (1<<(i)))
#define get(mask,i) (mask & (1<<(i)))
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const double PI = acos(-1);
const int64_t INF = (int64_t)1e18;

void solve() {
	int n;
	cin >> n;
	int64_t arr[n+1][3];
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	int64_t dp[n + 1][3];
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < 3; j++) {
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for(int i = 1; i <= n; i++) {
		dp[i][0] = max(arr[i][1] + dp[i-1][1], arr[i][2] + dp[i-1][2]);
		dp[i][1] = max(arr[i][0] + dp[i-1][0], arr[i][2] + dp[i-1][2]);
		dp[i][2] = max(arr[i][0] + dp[i-1][0], arr[i][1] + dp[i-1][1]);
	}
	cout << max({dp[n][0], dp[n][1], dp[n][2]});
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
