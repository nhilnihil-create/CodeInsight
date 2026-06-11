#include<bits/stdc++.h>

using namespace std;

const int INF=1e9;

int main (){
	int n;
	cin >> n;
	vector<int> steps={1,2};
	vector<int> h(n);
	vector<int> dp(n,INF);
	dp[0]=0;
	for(int i=0; i<n; ++i) cin >> h[i];
	for(int i=0; i<n; ++i){
		for(int j=0; j<(int)steps.size() && i+steps[j]<n; ++j) {
			dp[i+steps[j]]=min(dp[i+steps[j]],dp[i]+abs(h[i]-h[i+steps[j]]));
		}
	}
	cout << dp[n-1];
				
	return 0;
}
