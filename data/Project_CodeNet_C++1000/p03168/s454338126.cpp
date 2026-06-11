#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	cout.precision(10);
	int n;
	cin >>n;
	vector< vector<double> > dp(n+1,vector<double>(n+1));
	vector<double> v(n+1);
	for(int i = 1;i<=n;i++) cin >>v[i];
	dp[0][0]=1.0;
	for(int i = 1;i<=n;i++) {
		 dp[i][0] = dp[i-1][0]*(1-v[i]);
		 for(int j = 1;j<=i;j++) {
		 	dp[i][j] = dp[i-1][j-1]*v[i] +dp[i-1][j]*(1-v[i]);
		 }
	}
	double ans = 0.0;
	for(int i = (n+1)/2;i<=n;i++) ans = ans + dp[n][i];
	cout<<ans<<'\n';  
	return 0;
}