#include<bits/stdc++.h>

#define REP(i,n) for(ll i=0; i<n; i++)
#define REPN(i,n) for(ll i=0; i<n; i++,cout<<"\n")
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod1 1000000007
#define ll long long
#define clr0(arr) memset(arr,0,sizeof(arr))
#define clrval(arr,val) memset(arr,val,sizeof(arr))
using namespace std;

ll dp[100100][3];

ll memo(ll arr[][3], ll n, ll prev){

	if(n<=0)
		return 0;

	if(prev!=-1 && dp[n-1][prev]!=-1)
		return dp[n-1][prev];

	ll tempAns=INT_MIN;

	REP(i,3){
		if(i==prev)
			continue;

		ll val = arr[n-1][i] + memo(arr,n-1,i);
		tempAns=max(tempAns,val);
	}

	if(prev!=-1)
		dp[n-1][prev] = tempAns;
	return tempAns;
}

void solve(){

	ll n;
	cin>>n;

	ll arr[n][3];
	REP(i,n) 
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];

	clrval(dp,-1);

	cout<<memo(arr,n,-1)<<"\n";
	// cout<<rec(arr,n,-1)<<"\n";

}

int main(){
	// int t;
	// cin>>t;

	// while(t--){
		solve();
	// }

	return 0;
}
