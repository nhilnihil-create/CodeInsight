#include <bits/stdc++.h>
using namespace std;

#define mod ((int)1e9+7)

void test(vector<int> &arr, int k){
	int dp[arr.size()][k+1], p_sum[k+1];
	memset(dp, 0, sizeof(dp));
	memset(p_sum, 0, sizeof(p_sum));
	for(int i = 0; i < arr.size(); i++){
		dp[i][0] = 1;
	}
	for(int i = 1; i <= arr[0]; i++){
		dp[0][i] = 1;
	}
	for(int i = 1; i < arr.size(); i++){ 
		p_sum[0] = dp[i-1][0];
		for(int j = 1; j < k+1; j++){
			p_sum[j] = (((p_sum[j-1])%mod)+(dp[i-1][j]))%mod;
		}
		for(int j = 1; j < k+1; j++){ 
			if(j-arr[i]>=1){
				dp[i][j] = ((p_sum[j]%mod) - (p_sum[j-arr[i]-1]%mod))%mod;
				if(dp[i][j]<0){
					dp[i][j] = (dp[i][j]+mod)%mod;
				}
			}
			else{
				dp[i][j] = p_sum[j]; 
			}
		}
	}
	cout << dp[arr.size()-1][k] << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/input.txt", "r", stdin);
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	test(arr, k);
	return 0;
}