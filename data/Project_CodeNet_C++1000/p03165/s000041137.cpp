
// Problem : F - LCS
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_f
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;

#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define endl '\n'
#define vi vector<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define fi first
#define se second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()

const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N = 3e3 + 3;

vector<vector<pair<ll, pii>>> dp(N, vector<pair<ll, pii>>(N, {0, {0, 0}}));

int main() {
    SPEED;
    string s, t;
    cin>>s>>t;
    ll n1 = s.size(), n2 = t.size();
    s = '?' + s;
    t = '?' + t;
    for(ll i = 1; i <= n1; i++) {
    	for(ll j = 1; j <= n2; j++) {
    		if(s[i] == t[j]) {
    			dp[i][j] = {dp[i - 1][j - 1].fi + 1, {i - 1, j - 1}};
    		}
    		else {
    			if(dp[i - 1][j].fi > dp[i][j - 1].fi) {
    				dp[i][j] = {dp[i - 1][j].fi, {i - 1, j}};
    			}
    			else {
    				dp[i][j] = {dp[i][j - 1].fi, {i, j - 1}};
    			}
    		}
    	}
    }
    pii crr = {n1, n2};
    string ans;
    while(crr.fi != 0 && crr.se != 0) {
    	if(dp[crr.fi][crr.se].se.fi == crr.fi - 1 && dp[crr.fi][crr.se].se.se == crr.se - 1) {
    		ans.pb(s[crr.fi]);
    	}
    	crr = dp[crr.fi][crr.se].se;
    }
    reverse(all(ans));
    cout<<ans;
    return 0;
}