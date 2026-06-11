#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100002];

ll frog1(ll h[], ll n){
	if(n==1)
		return 0;
	if(n==2){
		return abs(h[2]-h[1]);
	}
	if(dp[n]!=-1)
		return dp[n];

	return dp[n] = min(abs(h[n] - h[n-1]) + frog1(h,n-1),abs(h[n] - h[n-2]) + frog1(h,n-2));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll h[n+1];
    for(int i=1;i<=n;i++){
    	cin>>h[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<frog1(h,n);
}
