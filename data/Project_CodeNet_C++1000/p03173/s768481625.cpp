#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<vector<ll>>& dp, vector<ll> a,int l, int r){
	if(dp[l][r]) return dp[l][r];
	if(l==r) return 0;
	ll fans = 1e18;
	for(int i=l; i<r; i++){
		fans = min(fans,solve(dp,a,l,i)+solve(dp,a,i+1,r));
	}
	return dp[l][r] = fans + a[r]-a[l-1];

}

int main(){
	int N;
	cin >> N;
	vector<ll> a(N+1);
	for(int i=1; i<=N; i++) cin >> a[i];
	for(int i=1; i<=N; i++){
		a[i] += a[i-1];
	}
	vector<vector<ll>> dp(N+1,vector<ll>(N+1));
	solve(dp,a,1,N);

	cout << dp[1][N] << endl;
	return 0;

}

