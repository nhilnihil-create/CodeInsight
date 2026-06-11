#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int a[N+1], b[N+1], c[N+1];
	int dp[N+1][4];
	for(int k = 1; k <= N; k++){
		cin >> a[k] >> b[k] >> c[k];
		dp[k][0] = 0;//margin
		dp[k][1] = 0;//a
		dp[k][2] = 0;//b
		dp[k][3] = 0;//c
	}
	a[0] = 0;
	b[0] = 0;
	c[0] = 0;
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[0][3] = 0;
	for(int i = 1; i <= N; i++){
		if(dp[i-1][1] > dp[i-1][2]){
			dp[i][3] = dp[i-1][1] + c[i];
		}else{
			dp[i][3] = dp[i-1][2] + c[i];
		}

		if(dp[i-1][2] > dp[i-1][3]){
			dp[i][1] = dp[i-1][2] + a[i];
		}else{
			dp[i][1] = dp[i-1][3] + a[i];
		}

		if(dp[i-1][3] > dp[i-1][1]){
			dp[i][2] = dp[i-1][3] + b[i];
		}else{
			dp[i][2] = dp[i-1][1] + b[i];
		}
	}

	int ans = max({dp[N][1], dp[N][2], dp[N][3]});

	cout << ans << endl;

	return 0;
}