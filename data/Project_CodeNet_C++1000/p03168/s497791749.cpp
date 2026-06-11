#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int n;
	cin >> n;

	double a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	double dp[n+1][n+1]; // [coins][heads]
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){ // we need exactly j heads from i coins
			dp[i][j] = dp[i-1][j]*(1.0-a[i-1]); // j heads from i-1 coins * ith tail
			if(j){
				dp[i][j] += dp[i-1][j-1]*a[i-1]; // j-1 heads from i-1 coins * ith head
			}
		}
	}

	double res=0;

	for(int i=(n+1)/2;i<=n;i++){
		res += dp[n][i];
	}
	// cout << setprecision(10) << res;
	printf("%.10f", res);
	return 0;
}