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

	int n, k; cin >> n >> k;
	vector<int> h(n); for(auto& x : h) cin >> x;

	vector<int> dp(n,1e9);

	dp[0] = 0;

	for(int i = 0; i < n; i++){
		for(int x = 1; x <= k; x++){
			if(i + x == n) break;
			dp[i+x] = min(dp[i+x], dp[i] + abs(h[i] - h[i+x]));
		}
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
