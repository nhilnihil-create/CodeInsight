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
	int a[n][n];
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	// FORWARD DP solution
	// what matters is the combination of girls to be used for boys upto a certian position
	// state -- mask of girls used
	// position is not a part of state as it directly comes from the number of set bits in the current mask
	// for each mask, iterate over every girl and check if it is compatible 
	// with the ith boy, if yes, add num of ways from previous mask
	int N = (1 << n);
	vector<ll> dp(N,0LL);
	dp[0] = 1LL;
	for(int mask = 0; mask < N; mask++){
		int i = bitcnt(mask);
		for(int j = 0; j < n; j++){
			if(a[i][j] && !(mask & (1 << j))){
				int next = mask ^ (1 << j);
				dp[next] += dp[mask];
				dp[next] %= mod;
			}
		}
	}
	cout << dp.back() << endl;

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
