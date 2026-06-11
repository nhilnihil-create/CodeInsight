#include <bits/stdc++.h>
using namespace std;
struct block{
	long long sum; 
	int W; int S;  
	long long V; 
}; 
bool cmp(const block &a, const block &b){
	return a.sum < b.sum; 
}
int main(){
	int N; cin >> N; 
	block B[1010]; 
	for(int i = 0; i < N; i++){
		cin >> B[i].W >> B[i].S >> B[i].V; 
		B[i].sum = B[i].W + B[i].S; 
	}
	sort(B, B+N, cmp); 
	long long dp[1010][10010] = {}; 
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= 10001; j++){
			dp[i][j] = -1e18;
		}
	}
	dp[0][0] = 0; 
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= 10000; j++){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]); 
			if(j <= B[i].S) dp[i+1][min(j+B[i].W, 10001)] = max(dp[i+1][min(j+B[i].W, 10001)], dp[i][j] + B[i].V); 
		}
		dp[i+1][10001] = max(dp[i+1][10001], dp[i][10001]); 
	}
	long long ans = 0; 
	for(int i = 0; i <= 10001; i++) ans = max(ans, dp[N][i]); 
	cout << ans << endl; 
}