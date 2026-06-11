#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(int l, int r, vector<ll> &sum, vector<vector<ll>> &dp){
	if(l == r)
		return 0;
	if(dp[l][r] != LLONG_MAX)
		return dp[l][r];
	ll &ret = dp[l][r];
	for(int i{l}; i < r; ++i){

		ret = min(ret, solve(l, i, sum, dp) + solve(i + 1, r, sum, dp) + sum[r + 1] - sum[l]);
	}
	return ret;
}

int main(){
	int n;
	cin>>n;
	vector<ll> inp(n);
	for(auto &x: inp)
		cin>>x;
	
	if(n == 1){
		cout<< 0;
		return 0;
	}

	vector<ll> sum(n + 1);
	for(int i{1}; i <= n; ++i)
		sum[i] = sum[i - 1] + inp[i - 1];

	vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MAX));
	cout<< solve(0, n - 1, sum, dp)<<endl;
	return 0;
}