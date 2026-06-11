#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int dp[n-1]={0};
	dp[0] = 0;
	for(int i=1;i<n;i++){
		dp[i] = INT_MAX;

		int step_1, step_2;
		if(i-1 >= 0){
			dp[i] = min(dp[i], dp[i-1] + abs(a[i]-a[i-1]));
		}
		if(i-2 >= 0){
			dp[i] = min(dp[i], dp[i-2] + abs(a[i]-a[i-2]));
		}
	}

	cout << dp[n-1] << endl;
	return 0;
}