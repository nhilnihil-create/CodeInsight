#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//dp[i][j]: The number of ways to distribute i candies 
// to first k children

//Initialization
//dp[0][0...N-1] = 1 and dp[i][0] = 1 if i<=ai

//Transitions
//dp[i][j] = dp[i][j-1] + dp[i-1][j-1] + ... + dp[i-A[j]][j-1]
//Use prefix_sums: prefix_sum[i] = dp[0][j-1] + dp[1][j-1] +...+ dp[i][j-1] 
//dp[i][j] = prefix_sum[i]-prefix_sum[i-A[j]-1]

//Order of evaluation
//Rowwise or Columwise

//Answer
//dp[K][N-1]

int dp[100005][105];
int A[105];
const int mod = 1e9+7;

int main(){
	int N, K;
	cin >> N >> K;
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
    
    for(int j=0; j<N; j++){
        dp[0][j] = 1;
    }
    //cout << "Hey" << endl;
    for(int i=0; i<=K; i++){
        if(i>A[0]){
            dp[i][0] = 0;
        }
        else{
            dp[i][0] = 1;
        }
    }
    //cout << "Hey" << endl;
	for(int j=1; j<N; j++){
		
		vector<int> prefix_sum(K+1,0);
		int sum = 0;
		for(int i=0; i<=K; i++){
			sum = ((sum) % mod + (dp[i][j-1])% mod ) % mod;
			prefix_sum[i] = sum;
		}
		
		for(int i=1; i<=K; i++){
			if(i-A[j]-1>=0){
				dp[i][j] = ((prefix_sum[i]) % mod - (prefix_sum[i-A[j]-1]) % mod) % mod;
			}
			else{
				dp[i][j] = prefix_sum[i];
			}
		}
	
	}

	cout << (dp[K][N-1] + mod) % mod << endl;
}



