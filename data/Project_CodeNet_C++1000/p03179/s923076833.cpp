#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;


#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
ll dp[3001][3001], mod = 1e9 + 7;
int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, i, ans = 0, j;
    cin>>n;
    string s;
    cin>>s;
    dp[1][1] = 1;
    for(i = 2; i <= n; i++) {
    	vector<ll> pref(n + 1, 0);
    	pref[0] = dp[i-1][0];
    	for(j = 1; j <= n; j++) {
    		pref[j] = (pref[j-1] + dp[i-1][j])%mod;
    	}
    	for(j = 1; j <= i; j++) {
    		if(s[i-2] == '<') {
    			dp[i][j] = pref[j-1];
    		} else {
    			dp[i][j] = ((pref[n] - pref[j-1])%mod + mod)%mod;
    		}
    	}
    }
    for(i = 1; i <= n; i++) {
    	// cout<<dp[3][i]<<" ";
    	ans = (ans + dp[n][i])%mod;
    }
    cout << ans << "\n";
}