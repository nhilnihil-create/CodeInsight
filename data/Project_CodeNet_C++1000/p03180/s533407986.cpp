#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	int lim = 1<<n;
	int cost[lim];
	memset(cost,0,sizeof(cost));
	for(int i=0; i<lim; i++){
		for(int j=0; j<n; j++){
			for(int k=j+1; k<n; k++){
				if(i&(1<<j) && i&(1<<k) ) cost[i]+=a[j][k]; 
			}
		}
	}
	//for(int i=0; i<lim; i++) cout<<cost[i]<<' ';
	
	int dp[lim];
	fill(dp,dp+lim,-1e17);
	dp[0] = 0;
	for(int m=1; m<lim; m++){
		for(int s=m; s; s=(s-1)&m){
			dp[m] = max(dp[m], dp[s] + cost[m^s]);
		}
		dp[m] = max(dp[m],dp[0]+cost[m]);
	}
	cout<<dp[lim-1];
}