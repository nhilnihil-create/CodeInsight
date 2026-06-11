/*"Everything in the universe is balanced. Every disappointment
   you face in life will be balanced by something good for you!
                Keep going, never give up."            */

#include "bits/stdc++.h"
using namespace std;

#define ll long long
const ll N=1e6+9;
const ll mod=1e9+7;

ll a[N];

int add(int n, int m){
	return (n+m)%mod;
}

void solve()
{    
    ll n, m ;
    cin >> n >> m;
    string grid[n+1] ;
    for(int i = 0 ; i<n; i++){
    	cin>>grid[i] ;
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1,0)) ;
    dp[1][1] = 1;
    for(int i=2; i<=n; i++){
    	if(grid[i-1][0]!='#')dp[i][1] = dp[i-1][1];
    }

    for(int i=2; i<=m; i++){
    	if(grid[0][i-1]!='#')dp[1][i] = dp[1][i-1];
    }

    for(int i=2; i<=n; i++){
    	for(int j=2; j<=m; j++){
    		if(grid[i-1][j-1]!='#'){
    			dp[i][j] = add((grid[i-2][j-1]=='#'?0:dp[i-1][j]), (grid[i-1][j-2]=='#'?0:dp[i][j-1])) ;
    		}
 //   		cout<<i<<j<<dp[i][j]<<" ";
    	}
   // 	cout<<"\n";
    }
    cout<<dp[n][m];

}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t=1;
    //pre();
    //cin>>t;
    while(t--)
    {
      solve();
    }  
}


// Xorawar