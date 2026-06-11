#include<bits/stdc++.h>
using namespace std;

int main(){
	// sengen
	int n;
	int dp[100010];
	// nyuryoku
	cin >> n;
	// keisan
	for(int i=1;i<=n;i++) dp[i] = INT_MAX;
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		int d = 1;
		while(d <= i){
			dp[i] = min(dp[i],dp[i-d] + 1);
			d *= 6;
		}

		d = 1;
		while(d <= i){
			dp[i] = min(dp[i],dp[i-d] + 1);
			d *= 9;
		}
	}
	// syutsuryoku
	cout << dp[n] << endl;
}