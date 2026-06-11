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
	ll n,k;
	cin>>n>>k;

	ll a[n];
	REP(i,n) cin>>a[i];

	ll dp[n];
	clr0(dp);

	dp[1]=abs(a[1]-a[0]);

	for(ll i=2; i<n; i++){
		ll tempAns=INT_MAX;
		for(ll j=1; j<=k; j++){
			if(i-j>=0){
				ll val = dp[i-j] + abs(a[i]-a[i-j]);
				tempAns=min(tempAns,val);
			} else break;
		}

		dp[i]=tempAns;
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
