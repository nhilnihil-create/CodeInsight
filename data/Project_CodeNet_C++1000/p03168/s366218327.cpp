#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n;
	cin >> n;
	
	double a[n]={};
	
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	double dp[n+1][n+1]={};
	memset(dp, 0, sizeof dp);
	
	// dp[i][j] -> first i coins choose and j of them is heads.
	// not coin drawn so probability 1.
	dp[0][0]=1.0;
	
	// ith coin first i drawn
	for(int i=1; i<=n; i++){
		// j of them is heads it may be 0 or all i so, 0 to i
		for(int j=0; j<=i; j++){
			// current coin drawn head
			// so mult a[i] and recurse next i-1, j-1 beause current heads
			if(j>0)
				dp[i][j]+=dp[i-1][j-1]*a[i-1];
				
			// if current not head then i-1, j because not head
			dp[i][j]+=dp[i-1][j]*(1-a[i-1]);
		}
	}
	
	// we need to sum all prob.
	// mans we drawns all n coins where >=n/2 is head sum all that
	double ans=0.0;
	
	for(int i=0; i<=n; i++){
		if(i > n-i)
			ans+=dp[n][i];
	}
	
	cout << setprecision(12) << fixed << ans << "\n";
}

int main(){
	solve();
}
