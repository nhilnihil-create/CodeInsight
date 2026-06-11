#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void test(vector<int> &arr){
	ll dp[arr.size()][arr.size()];
	memset(dp, 0, sizeof(dp));
	ll temp;
	for(int i = arr.size()-1; i >= 0; i--){
		for(int j  = i + 1; j < arr.size(); j++){
			temp = 0;
			dp[i][j] = LLONG_MAX;
			for(int k = i; k <= j; k++){
				temp+=arr[k];
			}
			for(int k = i; k < j; k++){
				dp[i][j] = min(temp + dp[i][k] + dp[k+1][j], dp[i][j]);
			}
		}
	}
	cout << dp[0][arr.size()-1];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/input.txt", "r", stdin);
	freopen("/home/afzalrao/Desktop/Academics/2nd Year/3rd Sem/ESO207/CP/Text Files/output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		 cin >> arr[i];
	}
	test(arr);
	return 0;
}