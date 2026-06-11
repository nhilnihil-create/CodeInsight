#include<bits/stdc++.h>

using namespace std;

int main(){
	long n;
	int k,i,j;
	long h[100000],dp[100000];
	cin >> n >>k;
	for(i=0;i<n;i++){
		cin >> h[i];
		dp[i] = 1e9+7;
	}	
	dp[0] = 0;
	for(i=0;i<n;i++){
		for(j=i+1;j<=i+k;j++){
			if(j<n){
				dp[j] = min(dp[j],dp[i]+ abs(h[i]-h[j]));
			}
		}
	}
	cout << dp[n-1];
	return 0;
}