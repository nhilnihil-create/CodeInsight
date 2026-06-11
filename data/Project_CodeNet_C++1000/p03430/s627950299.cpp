/*******************************************
*    Template created by Danel Batyrbek    *
*    All rights reserved 2018 (lol)        *
********************************************/

#include <bits/stdc++.h>

#define fr first
#define sc second
#define mkp make_pair
#define lrb lower_bound
#define upb upper_bound
#define pb emplace_back
#define ins insert
#define sz(x) x.size()
#define all(x) x.begin(), x.end()
#define speed_up ios_base :: sync_with_stdio(0);cin.tie(0)
#define skip continue
#define left(x) x << 1
#define rght(x) x << 1 | 1
#define forn(x, y, z) for(int x = y; x <= z; ++ x)
#define for1(x, y, z) for(int x = y; x >= z; -- x)
#define fname ""

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;
const int INF = 2e9 + 10;
const int mod = 1e9 + 7;
const ll LINF = 4e18 + 10;

string s;
int ans, k, now, prv, dp[301][301][301];
int main(){
#ifdef DANEL
	freopen("in", "r", stdin);
#else
	if(fname != ""){
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	}
#endif
	cin >> s;
	cin >> k;
	int n = s.size();
	for(int len = 1; len <= n; ++ len){
		for(int l = 0; l < n - len + 1; ++ l){
			int r = l + len - 1;
			if(len == 1){
				dp[l][r][0] = 1;
				skip;
			}
			for(int change = 0; change <= k; ++ change){
				dp[l][r][change] = dp[l + 1][r - 1][change];
				if(s[l] == s[r]){
					dp[l][r][change] = max(dp[l][r][change], dp[l + 1][r - 1][change] + 2);
				} else {
					dp[l][r][change] = max(dp[l][r][change], max(dp[l + 1][r][change], dp[l][r - 1][change]));
					if(change > 0) dp[l][r][change] = max(dp[l][r][change], dp[l + 1][r - 1][change - 1] + 2);
				}
			}
		}
	}
	forn(change, 0, k){
		ans = max(ans, dp[0][n - 1][change]);
	}
	cout << ans;
	return 0;
}