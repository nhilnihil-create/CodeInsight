#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100002];

ll frog2(ll h[], ll k, ll n){
	if(n==2)
		return abs(h[1]-h[2]);
	if(n<=1)
		return 0;

	if(dp[n]!=-1)
		return dp[n];
	ll temp = INT_MAX;
	for(int i=1;i<=k;i++){
      	if((n-i)==0)
          break;
		temp = min(temp,abs(h[n] - h[n-i]) + frog2(h,k,n-i));
	}
	
	return dp[n] = temp;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll h[n+1];
    for(int i=1;i<=n;i++){
    	cin>>h[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<frog2(h,k,n);
}
