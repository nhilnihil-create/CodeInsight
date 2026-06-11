#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e9
//dp[i][j] - till i, j heads probab
int main(){
	int n;cin>>n;
	vector<double> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	vector<vector<double> > dp(n,vector<double>(n+1,0));
	dp[0][0] = 1-v[0];dp[0][1] = v[0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=n;j++){
			if(j>i+1) continue;
			if(j==0) dp[i][j] = (1-v[i])*dp[i-1][j];
			else dp[i][j] = v[i]*dp[i-1][j-1]+(1-v[i])*dp[i-1][j];
		}
	}
	double ans=0;
	for(int j = (n/2)+1;j<=n;j++){
		ans+=dp[n-1][j];
	}
	printf("%.10lf\n", ans);
	// cout<<ans<<endl;
}