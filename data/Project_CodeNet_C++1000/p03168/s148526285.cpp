#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//State
//dp[i][j]: The probability of getting exactly i heads 
//	when first j coins are tossed

//Initialization
//dp[0][0...N-1] = 1
//dp[1][0] = p0 and dp[i][j] = 0 for all i>j

//Transitions 
//dp[i][j] = pj*dp[i-1][j-1] + (1-pj)*dp[i][j-1]

//Order of Evaluation 
//Rowwise or Columnwise

//Answer dp[N/2+1][N-1]+...+dp[N][N-1] 

int main(){
    int N;
	cin >> N;
	vector<double> P(N,0);
	vector<vector<double>> dp(N+1,vector<double>(N,0)); 
	for(int i=0; i<N; i++){
		cin >> P[i];
	}
	dp[0][0] = 1-P[0];
	dp[1][0] = P[0];
	for(int j=0; j<N; j++){
		for(int i=0; i<=j+1; i++){
		    //cout << "i "<< i << " j "<< j << endl;
			if(i-1>=0 && j-1>=0){
				dp[i][j] = dp[i][j] + P[j]*(dp[i-1][j-1]);
				//cout << dp[i][j] << " Hey" << endl;
			}
			if(j-1>=0){
				dp[i][j] = dp[i][j] + (1-P[j])*(dp[i][j-1]);
				//cout << dp[i][j] << " Hey" << endl;
			}
		}
	}
	/*for(int i=0; i<=N; i++){
	    for(int j=0; j<N; j++){
	        cout << dp[i][j] << " ";
	    }
	    cout << endl;
	}*/
	double result = 0;
	for(int i=N/2+1; i<=N; i++){
		result = result + dp[i][N-1];
	}
	printf("%0.10lf\n",result);
}
