#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//State
//dp[i][j]: The number of ways to reach the cell (i,j) from (1,1)

//Initialization
//dp[1,1] = 1

//Transitions
//if A[i-1][j]== . and A[i][j-1]== . then dp[i][j] = dp[i-1][j]+dp[i][j-1]

//Order of evaluation
//Rowwise or Columnwise

//Answer
//dp[H-1][W-1]

//Time Complexity: O(H*W)

const int mod = 1e9+7;

int main(){
	int H, W;
	cin >> H >> W;
	vector<vector<int>> dp(H, vector<int>(W,0));
	vector<vector<char>> A(H, vector<char>(W));

	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			cin >> A[i][j];
		}
	}
	
	dp[0][0] = 1;
    
    for(int i=1; i<H; i++){
        if(A[i][0]=='#') dp[i][0] = 0;
        else dp[i][0] = dp[i-1][0];
    }
    
    for(int i=1; i<W; i++){
        if(A[0][i]=='#') dp[0][i] = 0;
        else dp[0][i] = dp[0][i-1];
    }
    
	for(int i=1; i<H; i++){
		for(int j=1; j<W; j++){
		    if(A[i][j] == '#') dp[i][j] = 0;
		    else{
		        if(A[i-1][j]=='.' && A[i][j-1]=='.'){
			    	dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
		    	}
			    else if(A[i-1][j]=='#' && A[i][j-1]=='.'){
				    dp[i][j] = dp[i][j-1];
		        }
			    else if(A[i-1][j]=='.' && A[i][j-1]=='#'){
			    	dp[i][j] = dp[i-1][j];
			    }
			    else{
				    dp[i][j] = 0;
			    }   
		    }
		}
	}
	
	cout << dp[H-1][W-1] << endl;
}



