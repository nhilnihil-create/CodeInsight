#include<bits/stdc++.h>
using namespace std;

const int N = 3005;

int main(){
	cout << setprecision(10) << fixed;

	int n;
	cin >> n;

	vector<long double> p(n);
	long double dp[N][N];

	memset(dp , 0 , sizeof(dp));
	for(int i = 0 ; i < n ; i++){
		cin >> p[i];
	}

	dp[0][0] = (1-p[0]);
	dp[0][1] = p[0];

	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j <= n ; j++){
			dp[i][j] += dp[i-1][j]*(1-p[i]);	
			if (j > 0) dp[i][j] += dp[i-1][j-1]*(p[i]);
		}
	}

	long double ans = 0;
	for(int i = n/2 + 1 ; i < 3000 ; i++){
		ans += dp[n-1][i];
	}

	cout << ans << endl;
	return 0;
}
