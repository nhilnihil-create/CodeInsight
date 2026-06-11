#include <bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)

int solve(int mat[][21], int n, int dp[][1<<21], int index, int mask){
	if(dp[index][mask]!=-1){
		return dp[index][mask];
	}
	if(index==0){
		for(int i = 0; i < n; i++){
			if(mat[0][i] && (mask&(1<<i))){
				return dp[0][mask] = 1;
			}
		}
	}
	int curr_ans = 0;
	for(int i = 0; i < n; i++){
		if(mat[index][i] && (mask&(1<<i))){
			curr_ans = ((curr_ans%mod)+(solve(mat, n, dp, index-1, mask^(1<<i)))%mod)%mod;
		}
	}
	return dp[index][mask] = curr_ans%mod;
}

void test(int mat[][21], int n){
	int dp[21][1<<21];
	memset(dp, -1, sizeof(dp));
	cout << solve(mat, n, dp, n-1, (1<<n)-1) << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/input.txt", "r", stdin);
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	int mat[21][21];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> mat[i][j];
		}
	}
	test(mat, n);
	return 0;
}