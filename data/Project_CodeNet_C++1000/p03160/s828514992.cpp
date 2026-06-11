#include<bits/stdc++.h>

#define REP(i,n) for(ll i=0; i<n; i++)
#define REPN(i,n) for(ll i=0; i<n; i++,cout<<"\n")
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod1 1000000007
#define ll long long
#define clr0(arr) memset(arr,0,sizeof(arr))
#define clrval(arr,val) memset(arr,val,sizeof(arr))
using namespace std;

void solve(){
	ll n;
	cin>>n;

	ll a[n];
	REP(i,n) cin>>a[i];

	ll dp[n+1];
	clr0(dp);

	dp[1]=abs(a[1]-a[0]);

	for(ll i=2; i<n; i++){
		ll val1 = dp[i-1] + abs(a[i]-a[i-1]);
		ll val2 = dp[i-2] + abs(a[i]-a[i-2]);

		dp[i]=min(val1,val2);
	}

	cout<<dp[n-1]<<"\n";
}

int main(){
	// int t;
	// cin>>t;

	// while(t--){
		solve();
	// }

	return 0;
}
