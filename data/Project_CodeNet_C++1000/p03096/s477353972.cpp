#include<bits/stdc++.h> 
using namespace std ; 

const int N = 2e5 + 10 , mod = (int)1e9 + 7 ; 

int n , a[N] , dp[N] , sum[N] ; 

int32_t main() {
	cin >> n ; 
	for(int i = 1 ; i <= n ; ++i)
		cin >> a[i] ; 
	dp[0] = 1 ; 
	for(int i =  1 ; i <= n ; ++i) { 
		dp[i] = dp[i - 1] ; 
		if(a[i] != a[i - 1]) { 
			dp[i] += sum[a[i]] ; 
			sum[a[i]] += dp[i - 1] ; 
			dp[i] %= mod ; 
			sum[a[i]] %= mod ; 
		}
	}
	cout << dp[n] << endl ; 
}
