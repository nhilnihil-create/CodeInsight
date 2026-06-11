#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
ll a[25][25];
ll power[(1<<16)];
ll dp[(1<<16)],ans[(1<<16)];
int main(){
	cin>>n;
	for(ll i=0;i<n;++i){
		power[(1<<i)]=i;
	}
	for(ll i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	for(ll i=1;i<(1<<n);++i){
		ll lb=(i&(-i)),x=power[lb],st=i^lb;
		dp[i]=dp[st];
		for(int j=0;j<n;++j){
			if((1<<j)&st){
				dp[i]+=a[j][x];
			}
		}
	}
	for(ll i=1;i<(1<<n);++i){
		for(ll j=i;j;j=((j-1)&i)){
			ans[i]=max(ans[i],dp[j]+ans[i^j]);
		}
	} 
	cout<<ans[(1<<n)-1]<<'\n';
	return 0;
}