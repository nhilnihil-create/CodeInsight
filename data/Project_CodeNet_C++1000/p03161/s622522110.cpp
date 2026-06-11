#include<bits/stdc++.h>

using namespace std;

const int INF=1e9;

int main (){
	int n,k;
	cin >> n >> k;
	vector<int> h(n);
	vector<int> dp(n,INF);
	dp[0]=0;
	for(int i=0; i<n; ++i) cin >> h[i];
	for(int i=0; i<n; ++i){
		for(int j=1; j<=k && i+j<n; ++j) {
			dp[i+j]=min(dp[i+j],dp[i]+abs(h[i]-h[i+j]));
		}
	}
	cout << dp[n-1];
				
	return 0;
}

