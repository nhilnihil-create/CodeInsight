#include<bits/stdc++.h>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin>>n>>k;
	int A[n];
	int INF = 1e9+5;
	int dp[n];
	for (int i=0; i<n; i++){
		cin>>A[i];
		dp[i] = INF;
	}
	dp[0] = 0;
	for (int i=0; i<n; i++){
		for (int j=i; j<=i+k; j++){
			if(j == n) break;
			dp[j] = min(dp[j], dp[i] + abs(A[j] - A[i]));
		}
	}
	cout<<dp[n - 1];
}