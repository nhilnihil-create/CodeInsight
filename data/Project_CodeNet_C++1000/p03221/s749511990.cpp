#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {

	ll n,m;cin>>n>>m;
	vector<pair<ll,ll>> vc;
	ll a,b;
	ll d[m+1],f[m+1];
	map<ll,ll> mp;
	for(int i=1;i<=m;i++){
	cin>>d[i]>>f[i]	;
	vc.push_back({d[i],f[i]});}
	
	sort(vc.begin(),vc.end());
	int count=1;
	mp[vc[0].second]+=count;
	
	for(int i=1;i<vc.size();i++)
	{
		if(vc[i].first==vc[i-1].first){
		count++;
		mp[vc[i].second]+=count;}
		else{
		count=1;
		mp[vc[i].second]+=count;}
	}
	
	for(int i=1;i<=m;i++)
	{
		string res=to_string(d[i]);
		ll zero=6-res.length();
		for(int j=0;j<zero;j++)
		cout<<"0";
		cout<<res;
		
	res=to_string(mp[f[i]]);
     zero=6-res.length();
		for(int j=0;j<zero;j++)
		cout<<"0";
		cout<<res;
		
		cout<<"\n";
	}
	
	
}
	
	
	