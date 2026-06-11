//O.cpp
#include <bits/stdc++.h>
using namespace std;
#define N 1000000007;

int dp_util(vector< vector<int> > &dp, vector< vector<bool> > &A, int M, int women){

		if(dp[M][women] != -1)
			return dp[M][women];

		int n = A.size();
		int one = 1;
		int a, b;
		long long int ans = 0;
		if(!M){
			for(int j = 0; j < n; j++){
				if(A[0][j] && ((one << j) & women)){
					dp[0][women] = 1;
					return 1;
				}
			}
			dp[0][women] = 0;
			return 0;
		}
		
		
		
		for(int j = 0; j < n; j++){
			if(A[M][j] && ((one << j) & women)){
				
				b = women & ~(one << j);
				ans = (ans + dp_util(dp, A, M-1, b))%N;
			}
		}
		
		dp[M][women] = ans;
		return ans;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int M = pow(2, 21);
	int n;
	cin >> n;
	vector< vector<int> > dp(n, vector<int>(M, -1));

	vector< vector<bool> > A(n, vector<bool>(n, 0));
	int temp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> temp;
			A[i][j] = temp;
		}
	}

	int p = pow(2, n) - 1;
	int ans = 0;
	ans = dp_util(dp, A, n-1, p);
	cout << ans << endl;
	

	return 0;
}
//https://atcoder.jp/contests/dp/submissions/11206860


