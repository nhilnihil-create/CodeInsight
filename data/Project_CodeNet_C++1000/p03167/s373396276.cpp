#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1e9+7;
const int mxn=1e3+10;
ll dp[mxn][mxn];
char grid[mxn][mxn];
ll n,m;

inline ll add(ll a,ll b){
	return (a%mod + b%mod)%mod;
}

int main(){
	ll i,j;
	cin >> n >> m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin >> grid[i][j];
		}
	}
	dp[0][0]=1;
	dp[1][1]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(grid[i][j]=='.'){
				dp[i][j]=add(dp[i][j],dp[i-1][j]);
				dp[i][j]=add(dp[i][j],dp[i][j-1]);
			}
		}
	}
	cout << dp[n][m] << endl;
}