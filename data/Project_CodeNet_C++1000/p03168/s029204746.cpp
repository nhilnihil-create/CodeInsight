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
    cin >> n;
    vector<double> v(n);
    cout<<fixed<<setprecision(10);
    for(int i = 0 ; i < n ; i ++ )cin >> v[i];
    vector<vector<double>> dp(n+1, vector<double> (n+1,0)) ;

	
	dp[0][0]=1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=i; j++){
			dp[i][j+1] += dp[i-1][j]*v[i-1];
		}
		for(int j=0; j<=i; j++){
			dp[i][j] += dp[i-1][j]*(1-v[i-1]);
		}
	}/*
	for(int i = 0 ;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	double ans = 0 ;
	int nn = (n+1)/2;
	for(int i = n; i+nn-1>=n; i-- ){
		//cout<<i<<"<<";
		ans+=dp[n][i];
	}
	cout<<ans;

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