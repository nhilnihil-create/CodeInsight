#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n;
	vector<vector<int>> mat;
	for(int i = 0; i<n; i++){
	    vector<int> arr(3);
	    for(int i = 0l; i < 3; i++){
	        cin>>arr[i];
	    }
	    mat.push_back(arr);
	}
	
	vector<vector<int>> dp(n, vector<int>(3,0));
	dp[0][0] = mat[0][0];
	dp[0][1] = mat[0][1];
	dp[0][2] = mat[0][2];
	
	for(int i = 1; i < n; i++){
	    for(int j = 0; j < 3; j++){
	        dp[i][j] = max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + mat[i][j];
	    }
	}
	cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
	return 0;
}
