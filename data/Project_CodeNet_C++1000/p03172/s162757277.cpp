/*"Everything in the universe is balanced. Every disappointment
   you face in life will be balanced by something good for you!
                Keep going, never give up."            */
 
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
const ll N=1e6+9;
const ll mod=1e9+7;
 
ll a[N];
 
int add(int x, int y){
	return (x+y)%mod;
}
 
void solve()
{    
    ll n, m ;
    cin >>n >>m ;
    vector<int> a(n+1);
    vector<vector<long long int>> dp(n+1,vector<long long int>(m+1,0)) ;
    for(int i=1 ;i<=n; i++)cin>>a[i];
    if(!m){
    	cout<<1;return;
    }
    for(int i = 0 ; i<=m; i++){
    	dp[0][i] = 1 ;
    }
    for(int i=1; i<=n; i++){
    	for( int j = 0 ; j<=m ; j++){
	
			if(j)dp[i][j] = dp[i][j-1];    
	       	if(j<=a[i]){
	    		dp[i][j] = add(dp[i][j], dp[i-1][j]);
	    	}
	    	else {
	    		dp[i][j] = add(dp[i][j] , (dp[i-1][j]-dp[i-1][j-a[i]-1]+mod)%mod) ;
	    	}
 
    		//cout<<dp[i][j]<< " ";
    	}
    	//cout<<"\n";
    }	
    cout<< (dp[n][m] - dp[n][m-1]+ mod) % mod;
 
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