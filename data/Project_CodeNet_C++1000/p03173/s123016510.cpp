#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//State
//dp[i][j]: The minimum cost to merge the fruits between
//	A[i]...A[j]

//Initialization
//dp[i][i] = A[i]

//Transitions
//dp[i][j] = max(dp[i][k]+dp[k+1][j]) k E [i,j-1]

//Order of evaluation
//Diagonal or length of substring

//Answer
//dp[0][N-1]

//Time Complexity = O(n^3)

const long long INF = 1e18+7;
vector<vector<long long>> dp(405, vector<long long>(405, INF));
long long prefix[405];
int A[405];

int main(){
	int N;
	cin >> N;
	long long sum = 0;
	for(int i=0; i<N; i++){
		cin >> A[i];
		dp[i][i] = 0;
		sum = sum + A[i];
		prefix[i] = sum;
	}
	for(int rMinusl=1; rMinusl<N; rMinusl++){
		for(int l=0; l<N; l++){
			int r = l+rMinusl;
			if(r<N){
			    for(int k=l; k<=r-1; k++){
			        long long temp1 = prefix[k]-prefix[l]+A[l];
			        long long temp2 = prefix[r]-prefix[k+1]+A[k+1];
				    dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]+temp1+temp2);
		    	}   
			}
		}
	}
	cout << dp[0][N-1];
}


