/*@author Vipen Loka*/
#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define deb(x) cout << #x << ':' << x << '\n';

using namespace std;

void solve(){
	int i,j;
	int r,c;
	cin >> r >> c;
	vector<vector<int>> m(r,vector<int>(c));
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			char t;cin >> t;
			m[i][j]=t;
		}
	}
	vector<vector<ll>> dp(r,vector<ll>(c,0));
	dp[0][0]=m[0][0]=='.'? 1: 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(m[i][j]=='#')continue;

			if(i>0 && j>0){
				dp[i][j]=dp[i][j-1]+dp[i-1][j];
			}
			else if(i>0){
				dp[i][j]=dp[i-1][j];
			}
			else if(j>0){
				dp[i][j]=dp[i][j-1];
			}
			dp[i][j]%=mod;
		}
	}

	printf("%lld\n",dp[r-1][c-1]);

	
}


int main(){
	int T=1;
	// cin >> T;
	while (T--){
		solve();
	}
}
