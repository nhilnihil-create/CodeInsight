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
    ll n, m ,k;
    cin >> n ;
    vector<int> a(n), b(n), c(n) ;
    for(int i=0 ; i<n; i++) {
    	cin >> a[i] >> b[i] >> c[i] ;
    }
    vector<vector<int>> dp(n, vector<int>(3)) ;

    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    for(int i=1; i<n; i++) {
    	dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]) ;
    	dp[i][2] = c[i] + max(dp[i-1][1], dp[i-1][0]) ;
    	dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]) ;
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) ;

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