/*"Everything in the universe is balanced. Every disappointment
   you face in life will be balanced by something good for you!
                Keep going, never give up."            */

#include "bits/stdc++.h"
using namespace std;

#define ll long long
const ll N=1e6+9;
const ll mod=1e9+7;

ll a[N];

void solve()
{    
    ll n, m ;
    cin >> n ; 
    vector<int> height(n);
    for ( int i=0 ; i<n; i++){
    	cin>>height[i] ;
    }
    vector<int> dp(n);
    dp[0] = 0 ;
    dp[1] = ( abs(height[1]-height[0]) + dp[0] )  ;

    for(int i = 2; i<n; i++ ) {
    	dp[i] = min(abs(height[i]-height[i-1]) + dp[i-1] , abs(height[i]-height[i-2]) + dp[i-2] ) ;
    }
    cout<<dp[n-1];

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