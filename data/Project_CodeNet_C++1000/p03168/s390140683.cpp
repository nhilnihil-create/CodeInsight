#include<bits/stdc++.h> 
using namespace std;

double solve(vector<double>& p, int N){
	int heads=N;
	vector<vector<double>>dp(N+1,vector<double>(N+1,0.0));
	dp[0][0]=1.0;
	for (int i=1;i<=N;i++){
		for (int j=0;j<=i;j++){
			if (j==0) dp[i][j]=dp[i-1][j]*(1.0-p[i-1]);
			else dp[i][j]=dp[i-1][j-1]*p[i-1]+dp[i-1][j]*(1.0-p[i-1]);
		}
	}
	double ans=0.0;
	for (int i = (N + 1) / 2; i <= N; i += 1) 
        ans += dp[N][i];
	return ans;

}
signed main() {
	int N;
    cin>>N;
    vector<double> prob(N);
    for (int i=0;i<N;i++){
    	cin>>prob[i];
    }
	cout<< setprecision(16)<<solve(prob,N)<<endl;
    return 0; 
}
