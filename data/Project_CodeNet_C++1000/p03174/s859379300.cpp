#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define myPair pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define qmax priority_queue<int>
#define qmin priority_queue<int,vector<int>,greater<int>>
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)

const int mxn = (1 << 22), MOD = 1e9 + 7;
int dp[mxn], a[22][22], n;

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	FOR(m, 1, n) {
		FOR(w, 0, n - 1) {
			cin >> a[m][w];
		}
	}

	// dp[mask] = number of ways to pair first 'i' men
	//			  with remaining subset 'mask' of women

	dp[0] = 1;

	FOR(mask, 1, (1 << n) - 1) {
		int cur = __builtin_popcount(mask);
		dp[mask] = 0;
		FOR(w, 0, n - 1) {
			if(a[cur][w] && (mask & (1 << w)))
				dp[mask] = (dp[mask] + dp[mask ^ (1 << w)]) % MOD;
		}
	}

	cout << dp[(1 << n) - 1];

	return 0;
}