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


void solution(){

	int n; cin >> n;
	vector<int> h(n); for(auto& x : h) cin >> x;

	vector<int> dp(n,1e9);

	dp[0] = 0;

	for(int i = 0; i+1 < n; i++){
		dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
		if(i+2 < n)
			dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));		
	}

	cout << dp[n-1] << endl;




	
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
