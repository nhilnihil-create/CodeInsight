#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m,x,y,p,q;
	cin>>n;
	vector<double>P(n);
	for(int i=0;i<n;i++) cin>>P[i];
	vector<vector<double>>dp(n,vector<double>(n+1)); 
	//dp[i][j] means probability of having j heads till ith index;
	dp[0][0]=1-P[0];
	dp[0][1]=P[0];
	for(int i=1;i<n;i++){
		dp[i][0]=(1-P[i])*dp[i-1][0];
		
		for(int j=1;j<=(i+1);j++){
			dp[i][j]=P[i]*dp[i-1][j-1]+(1-P[i])*(dp[i-1][j]);
			
		}
		
	}
	double ans=0;
	for(int j=n/2+1;j<=n;j++) ans+=dp[n-1][j];
	cout<<setprecision(15)<<ans<<"\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
	
	solve();

}