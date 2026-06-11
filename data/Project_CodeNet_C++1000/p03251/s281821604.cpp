#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n,m,x,y;
	cin>>n>>m>>x>>y;
	vector<ll>  v1(n,0),v2(m,0);
	for(ll i=0;i<n;i++) cin>>v1[i];
	for(ll i=0;i<m;i++) cin>>v2[i];
	
	bool bb=1;
	ll maxi=INT_MIN,mini=INT_MAX;
	for(ll i=0;i<n;i++) maxi=max(maxi,v1[i]);
	for(ll i=0;i<m;i++) mini=min(mini,v2[i]);
	for(ll i=maxi;i<=mini;i++){
		if(x<i&&i<=y&&i>maxi&&i<=mini){
			bb=0;
		}
	}
	
	if(bb==1) cout<<"War";
	else cout<<"No War";
}