#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, K;
	int N;
	cin >> N >> K;
	long long int NN = 1000000007;
	vector<int>A(N, 0);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	if(!N){
		cout << 0 << endl;
		return 0;
	}
	vector< vector<int> > dp(2, vector<int>(K+1, 0));
	for(int i = 0; i <= A[0]; i++)
		dp[0][i] = 1;
	if(N == 1){
		cout << dp[0][K] << endl;
		return 0;
	}
	long long int sum = 0;
	for(int i = 0; i <= K; i++){
		dp[0][i] = (sum + dp[0][i])%NN;
		sum = dp[0][i];
	}

	for(int n = 1; n < N; n++){
		for(int k = 0; k <= K; k++){
			
			// for(int j = 0; j <= A[n]; j++){
			// 	if(j > k)
			// 		break;
			// 	sum = (sum + dp[0][k - j])%NN;
			// }
			if( k - A[n] > 0){
				if(dp[0][k] - dp[0][k - A[n] - 1] < 0){
					dp[1][k] = (NN + dp[0][k] - dp[0][k - A[n] - 1])%NN ;
				}else{
					dp[1][k] = dp[0][k] - dp[0][k - A[n] - 1];
				}
				
			}
			else
				dp[1][k] = dp[0][k];
		}
		long long int sum = 0;
		for(int k = 0; k <= K; k++){
			
				//cout << dp[1][k] << " ";
			dp[0][k] = (sum + dp[1][k])%NN;
			sum = dp[0][k];
		}
		
			//cout << endl;
	}

	cout << dp[1][K] << endl;
	return 0;
}
