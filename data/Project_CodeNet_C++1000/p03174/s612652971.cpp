/*"Everything in the universe is balanced. Every disappointment
   you face in life will be balanced by something good for you!
                Keep going, never give up."            */

#include "bits/stdc++.h"
using namespace std;

#define ll long long
const ll N=1e6+9;
const ll mod=1e9+7;

ll a[25][25],n;
ll dp[(1<<21)];

ll add(ll x, ll y){
	return (x+y)%mod;
}

ll go( ll mask){
	ll men = __builtin_popcount(mask);
	if(men == n) {
		return 1;
	}

	ll &ans = dp[mask]; 
	if(ans!=-1)return ans;

	ans = 0 ;
	for(int i = 1; i<=n; i++){
		if( !( mask&(1<<(i-1)) ) && a[men+1][i] ) {
			ans = add(ans, go(mask|(1<<(i-1)))) ;
		}
	}
	//cout<<men<<" "<<mask<<" "<<ans<<"\n";
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

    cout<<  go(0);
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