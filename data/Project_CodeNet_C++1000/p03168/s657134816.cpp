#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<double> p(N);
	for(int i=0; i<N; i++) cin >> p[i];

	vector<vector<double>> dp(N,vector<double>(N+1));
	dp[0][0] = 1-p[0];
	dp[0][1] = p[0];
	for(int i=1; i<N; i++){
		for(int j=0; j<N; j++){
			dp[i][j]   += dp[i-1][j] * (1-p[i]);
			dp[i][j+1] += dp[i-1][j] * p[i];
		}
	}

	double ans = 0;
	for(int i=N/2+1; i<=N; i++) ans += dp[N-1][i];
	printf("%.9lf\n",ans);
	return 0;
}

