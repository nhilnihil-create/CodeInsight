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
int n;

void solution(){
	cin >> n;
	a = vector<ll>(n); for(auto& x : a) cin >> x;
	// state -- only depends on the portion of the array which is remaining
	// dp[i][j] -- minimum cost to combine array from a[i]....a[j]
	// for calculating answer for each state, we consider k to be the position
	// between i and j where elements at k and k+1 will be the LAST ones to be merged,
	// so the cost in that case would be the sums of a[i]..a[k] + a[k+1]..a[j]
	// dp[i][j] = min over left + right + dp[i][k] + dp[k+1][j];
	vector<ll> pre(n,0);
	pre[0] = a[0];
	for(int i = 1; i < n; i++) pre[i] = pre[i-1]+a[i];
	vector<vector<ll>> dp(n,vector<ll>(n,1e18));
	for(int x = 0; x < n; x++){
		for(int y = 0; y+x < n; y++){
			int i = y, j = y+x;
			if(i == j) dp[i][j] = 0;
			else if(i+1 == j) dp[i][j] = a[i]+a[j];
			else{
				for(int k = i; k < j; k++){
					ll left = pre[k] - (i == 0? 0 : pre[i-1]);
					ll right = pre[j] - pre[k];
					dp[i][j] = min(dp[i][j], left + right + dp[i][k] + dp[k+1][j]);
				}
			}
		}
	}
	cout << dp[0][n-1] << endl;
	
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
