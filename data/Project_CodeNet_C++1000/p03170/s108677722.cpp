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

int dp[100003][2];
vector<int> a;
int n, k; 

bool solve(int stones, bool alice){
	if(dp[stones][alice] != -1) return dp[stones][alice];
	for(int x : a){
		if(stones >= x && !solve(stones-x,!alice)){
			return dp[stones][alice] = 1;
		}
	}
	return dp[stones][alice] = 0;
}

void solution(){
	cin >> n >> k;
	a = vector<int>(n); for(auto& x : a) cin >> x;
	// Game Theory DP - 
	// here state only depends on number of stones left 
	// and whos turn it is to move
	memset(dp,-1,sizeof(dp));
	dp[0][1] = dp[0][0] = 0;
	cout << (solve(k,1) ? "First\n" : "Second\n");
	return;
}	


int main(){ 

	fio; // fast input output
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// GOOGLE //
		// cout << "Case #" << i << ": ";
		solution();
	} 
	return 0;
}
