/*"Everything in the universe is balanced. Every disappointment
   you face in life will be balanced by something good for you!
                Keep going, never give up."            */

#include "bits/stdc++.h"
using namespace std;

#define ll long long
const ll N=1e6+9;
const ll mod=1e9+7;

ll a[25][25],n;
ll dp[23][(1<<21)];

ll add(ll x, ll y){
	return (x+y)%mod;
}

ll go(ll men, ll mask){
	if(men == n+1) {
		if(mask == (1<<n)-1) return 1;
		else return 0;
	}

	ll &ans = dp[men][mask]; 
	if(ans!=-1)return ans;

	ans = 0 ;
	for(int i = 1; i<=n; i++){
		if( !( mask&(1<<(i-1)) ) && a[men][i] ) {
			ans = add(ans, go(men+1, mask|(1<<(i-1)))) ;
		}
	}
	return ans;
}

void solve()
{    
    cin>>n ;
    memset(dp,-1,sizeof dp);
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=n; j++){
    		cin >> a[i][j] ;
    	}
    }

    cout<<  go(1,0);
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