#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//State
//dp[mask]: The number of ways of matcxhing the subset of women
// represnted by mask(each bit corresponds to a woman) to the first i number of men 
// where i = count of ones in mask

//Initialization
//dp[0] = 1

//Transitions
//dp[mask] = dp[mask]+dp[newmask] for all newmask obtaining by deleting a one from the mask

//Order of evaluation
//1 to 2^N-1 (increasing order of mask)

//Answer
//dp[(1<<N)-1]

//Time Complexity: O(N*2^N)

const int mod = 1e9+7;
int A[21][21];
int dp[(1<<21)-1]={0};

vector<int> getOnes(int mask, int N){
	vector<int> result;
	for(int i=0; i<N; i++){
		if((mask & (1<<i)) != 0){
			result.push_back(i);
		}
	}
	return result;
}

int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> A[i][j];
		}
	}
	dp[0] = 1;
	for(int mask=1; mask<(1<<N); mask++){
		vector<int> ones = getOnes(mask, N);
		int man = ones.size()-1;
		//cout << mask<<" "<< man << ones.size() << endl;
		for(int woman: ones){
			if(A[man][woman]==1){
				int newMask = (mask & ~(1<<woman));
				dp[mask] = (dp[mask] + dp[newMask]) % mod; 
			}
		}
	}
	/*for(int i=0; i<(1<<N); i++){
	    cout << dp[i] << " ";
	}
	cout << endl;*/
	cout << (dp[(1<<N)-1]) % mod << endl;
}