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
    cin >>n >>m ;
    vector<int> a(n), dp(m+1,0) ;
    for(int i = 0 ;i<n; i++)cin>>a[i];
    for(int i=0; i<=m; i++){
    	int flag = 0 ; 
    	for( int j = 0 ; j< n; j++){
    		if(i-a[j]>=0 && dp[i-a[j]]==0)flag = 1 ;
    	}
    	dp[i] = flag ;
    	//cout<<i<<dp[i]<<"<<";
    }	
   	if(dp[m])cout<<"First";
   	else cout<<"Second";

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