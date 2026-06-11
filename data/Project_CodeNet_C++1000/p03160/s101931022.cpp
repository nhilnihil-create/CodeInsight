#include<bits/stdc++.h>

using namespace std;
int main(){
  	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	int A[n];
	int INF = 1e9+5;
	int dp[n];
	for (int i=0; i<n; i++){
		cin>>A[i];
		dp[i] = INF;
	}
	dp[0] = 0;
	for (int i=0; i<n; i++){
		if(i + 2 < n){
			int k = min(dp[i] + abs(A[i + 2] - A[i]), dp[i + 1] + abs(A[i + 2] - A[i + 1])) ;
			dp[i + 2] = min(dp[i + 2], k); 
			dp[i + 1] = min(dp[i + 1], dp[i] + abs(A[i + 1] - A[i]));
		}
		else if(i + 1 < n){
			dp[i + 1] = min(dp[i] + abs(A[i + 1] - A[i]), dp[i + 1]);
		}
	}
	cout<<dp[n - 1];
}