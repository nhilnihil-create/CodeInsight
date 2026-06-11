#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define rep(i, x) for(ll i = 0; i < x; i++)
#define rep2(i, x) for(ll i = 1; i <= x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;

ll dp[1002][1002]; char a[1002][1002];
signed main() {
	ll n, m; cin >> n >> m;
	rep2(i, n) {
		rep2(j, m) {
			cin >> a[i][j];
		}
	}
	dp[1][1] = 1;
	rep2(i, n) {
		rep2(j, m) {
			if (a[i][j] != '#') {
				dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % mod;
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}