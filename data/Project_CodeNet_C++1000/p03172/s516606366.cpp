#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define bitcnt(v) __builtin_popcount(v)
#define all(v) v.begin(), v.end()

vector<ll> a;
int n, k; 
int mod = 1e9 + 7;

void solution(){
	cin >> n >> k;
	a = vector<ll>(n); for(auto& x : a) cin >> x;
	// dp[i][k] -- number of ways to distribute k candies among children upto i'th index
	// so , dp[i][k] = dp[i-1][k] + dp[i-1][k-1] + ... + dp[i-1][k-a[i]]
	// number of states - O(nk)
	// complexity for calculating each state - O(k)
	// total time - O(nkk)
	// using prefixes, calculate for each state in constant time
	// so, dp[i][k] = pre[k] - pre[k-a[i]-1], where pre is prefixes for dp[i-1]
	ll dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	vector<ll> pre(k+1,1LL);
	dp[0][0] = 1LL;
	for(int i = 1; i <= n; i++){
		vector<ll> new_pre(k+1,1LL);
		dp[i][0] = 1LL;
		for(int j = 1; j <= k; j++){
			int l = max(0LL, j-a[i-1]);
			int r = j;
			dp[i][j] = (pre[r] - (l == 0? 0 : pre[l-1]) + mod) % mod;
			new_pre[j] = (new_pre[j-1] + dp[i][j]) % mod;
		}
		swap(pre, new_pre);
	}
	cout << dp[n][k] % mod << endl;
}	


int main(){ 

	fio;
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solution();
	} 
	return 0;
}
