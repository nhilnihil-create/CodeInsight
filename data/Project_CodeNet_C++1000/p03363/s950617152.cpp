#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll a[200010];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<n;i++){
		a[i]=a[i]+a[i-1];
	}
	map<ll,ll>b;
	for(ll i=0;i<n;i++){
		ll now=a[i];
		b[now]++;
	}
	ll ans=0;
	for(auto itr=b.begin();itr!=b.end();itr++){
		ll now=itr->first;
		ll val=itr->second;
		if(now==0){
			ans+=val*(val+1)/2;
		}
		else{
			ans+=val*(val-1)/2;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}