#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//using namespace std;

int main(){
	int n;
	cin>>n;
//	double A[n];
	vector<double>A(n,0);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
//	double dp[n+1][n+1];
	vector<vector<double>>dp(n+1, vector<double>(n+1, 0.0));
//	memset(dp, 0.0, sizeof(dp));
	dp[0][0]= 1;
//	cout<<"hi";
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0) dp[i][j]= dp[i-1][j]*(1-A[i-1]);
			else {
				dp[i][j]= (dp[i-1][j])*(1.0-A[i-1])+ (dp[i-1][j-1])*(A[i-1]);
			}
//			cout<<dp[i][j]<<" ";
//			dp[i][j+1] += dp[i-1][j]*(A[i-1]);
//      dp[i][j] += dp[i-1][j]*(1.0 - A[i-1]); 
		}
	}
	double ans= 0.0;
	for(int i=n;i>n/2;i--){
		ans= ans+ dp[n][i];
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
//	cout<<ans<<endl;
	return 0;
	
}