#include <bits/stdc++.h>
#ifdef LOCAL
#include <pprint.hpp>
#endif
#define endl "\n";
#define pb push_back
#define md 1000000007
#define ll long long int
#define all(v) v.begin(),v.end()
ll power(ll a,ll b){ll z=1;while(b){if(b&1){z*=a;z%=md;}a*=a;a%=md;b/=2;}return z%md;}
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	//You need to change array size!
	#ifndef LOCAL
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	#endif 
	
	ll n,k;
	cin>>n>>k;
	ll dp[k+1];
	dp[0]=0;
	ll v[n];
	for(int i=0;i<n;++i){
		cin>>v[i];
	}	
	
	for(int i=1;i<=k;++i){
		ll ans=1;
		for(int j=0;j<n;++j){
			if(i-v[j]>=0)
				ans *= dp[i-v[j]];
		}
		dp[i]=!ans;
	}
	
	cout<<(dp[k]?"First":"Second");
	
	return 0;	
}