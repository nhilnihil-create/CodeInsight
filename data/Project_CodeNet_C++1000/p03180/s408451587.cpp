#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N; 
	long long A[16][16]; 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> A[i][j]; 
		}
	}
	long long P[65536] = {}; 
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			for(int k = 0; k < (1 << N); k++){
				if(((k >> i) & 1) && ((k >> j) & 1)) P[k] += A[i][j];
			}
		}
	}
	long long dp[65536] = {}; 
	for(int i = 1; i < (1 << N); i++) dp[i] = -1e18; 
	for(int bit = 1; bit < (1 << N); bit++){
		int now = bit; 
		while(1){
			dp[bit] = max(dp[bit], dp[now] + P[bit - now]); 
			now = (now - 1) & bit; if(now == bit) break; 
		}
	}
	cout << dp[(1 << N) - 1] << endl; 
}