#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int a[n];

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int dp[n-1]={0};
	dp[0] = 0;
	for(int i=1;i<n;i++){
		int temp = INT_MAX;
		for(int j=1;j<=k;j++){
			if(i-j >= 0){
				temp = min(temp, dp[i-j] + abs(a[i]-a[i-j]));
			}
		}
		dp[i] = temp;
	}

	cout << dp[n-1] << endl;
	return 0;
}