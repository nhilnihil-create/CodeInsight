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

int mod = 1e9 + 7;

void solution(){
	int n; cin >> n;
	string s; cin >> s;
	// dp[i][j] -- number of permutations upto i ending in j, only for numbers from 1 -- i
	ll dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	dp[1][1] = 1;
	vector<ll> pre(n+1,0);
	for(int i = 1; i <= n; i++) pre[i] = 1;
	for(int len = 2; len <= n; len++){
		vector<ll> new_pre(n+1,0);
		for(int num = 1; num <= len; num++){
			if(s[len-2] == '>'){
				dp[len][num] += (pre[len-1] - pre[num-1] + mod) % mod;
			}
			else{
				dp[len][num] += pre[num-1];
			}
			dp[len][num] %= mod;
			new_pre[num] = (new_pre[num-1] + dp[len][num]) % mod;
		}
		swap(pre,new_pre);
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans += dp[n][i];
		ans %= mod;
	}
	cout << ans << endl;

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
