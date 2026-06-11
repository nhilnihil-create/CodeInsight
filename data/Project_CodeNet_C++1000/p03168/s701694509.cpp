#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double> p(n);
	for(int i=0; i<n; i++) {
		cin >> p[i];
	}
	vector< vector<double> > dp(n+1, vector<double>(n+1, 0));
	dp[0][0]=1;
	for (int i=1; i<=n; i++) {
		dp[i][0] = dp[i-1][0]*(1-p[i-1]);
		dp[i][i] = dp[i-1][i-1]*p[i-1];
	}
	for (int i=2; i<=n; i++) {
		for (int j=1; j<i; j++) {
			dp[i][j] = dp[i-1][j-1]*p[i-1] + dp[i-1][j]*(1-p[i-1]);
		}
	}
	double ans=0;
	for (int i=(n+1)/2; i<=n; i++)
		ans+=dp[n][i];
	cout << setprecision(15)<< ans << endl;
  	return 0;
}
