#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, m;
	cin>>n>>m;
	vector<vector<char>> grid(n, vector<char>(m));
	ll i, j;
	ll mod = 1e9+7;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			cin>>grid[i][j];
	}
	vector<vector<ll>> dp(n, vector<ll>(m));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(grid[i][j]=='#')
				dp[i][j]=0;
			else{
				if(i==0 && j==0)
					dp[i][j] = 1;
				else if(i==0)
					dp[i][j] = dp[i][j-1];
				else if(j==0)
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
			}
		}
	}
	cout<<dp[n-1][m-1]<<"\n";
	return 0;
}