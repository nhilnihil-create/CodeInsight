#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	vi a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	V<vi> dp(n + 1, vi(n + 1));
	for(int r = 1; r <= n; r++) {
		for(int l = r - 1; l >= 1; l--) {
			dp[l][r] = 1e18;
			for(int m = l; m < r; m++) {
				dp[l][r] = min(dp[l][r], dp[l][m] + dp[m+1][r] + a[r] - a[l-1]);
			}
		}
	}
	cout << dp[1][n] << endl;
	
}

