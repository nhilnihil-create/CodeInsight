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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, M = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	vi dp(k + 1);
	dp[0] = 1;
	for(int i = 0; i < n; i++) {
		for(int i = 1; i <= k; i++) dp[i] = (dp[i] + dp[i - 1]) % M;
		int x;
		cin >> x;
		vi nw_dp(k + 1);
		for(int i = 0; i <= k; i++) {
			int l = i - x;
			if(l > 0) nw_dp[i] = (dp[i] - dp[l - 1] + M) % M;
			else nw_dp[i] = dp[i];
		}
		dp = nw_dp;
	}
	cout << dp[k] << endl;
}

