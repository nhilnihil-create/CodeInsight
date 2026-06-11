#include<bits/stdc++.h>
using namespace std;
#define ll long long

// DP+bit masking

// when N<=21 most of the time it is bitmasking

const int mod = 1e9+7;

void solve() {
	int n;
	cin >> n;
	
	int a[n][n]={};
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> a[i][j];
	
	vector<int> dp(1<<n); // O(2^n)
	dp[0]=1; // there is 1 way to match with no one.
	
	// Here mask is refer as set of womens
		
	// use mask for making set of women because 1 women belong to one man
	for(int mask=0; mask < (1<<n)-1; mask++){
		
		int man = __builtin_popcount(mask);
		
		// loop to all women
		for(int women=0; women<n; women++){
			
			// if there is compatibility man and women and women is not belong to other group man
			if(a[man][women] && !(mask & (1<<women))) {
				
				// set that women bit
				int mask2 = mask ^ (1<<women);
				
				// add new mask means set of women with old mask.
				dp[mask2]+=dp[mask];
				
				if(dp[mask2] >= mod)
					dp[mask2] -= mod;
				
			}
		}
	}
			
	cout << dp[(1<<n)-1] << "\n";
	
}

int main(){
	solve();
}
