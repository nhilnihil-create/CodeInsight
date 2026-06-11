#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxB(vector<ll>&h,vector<ll>&a){
	map<ll,ll> hv;
	vector<ll> dp(h.size());
	ll maxv=0;
	for(ll i=0;i<h.size();i++){
		auto it=hv.lower_bound(h[i]+1);
		if(it==hv.begin()){
			dp[h[i]]=a[i];
			hv[h[i]]=dp[h[i]];		
		}
		else{
			it--;
			dp[h[i]]=a[i]+it->second;
			hv[h[i]]=dp[h[i]];
		}
		auto It=hv.upper_bound(h[i]);
		while(It!=hv.end() && It->second<=dp[h[i]]){
			auto temp=It;
			temp++;
			hv.erase(It);
			It=temp;
		}
		maxv=max(maxv,dp[h[i]]);
	}
	return maxv;
}

int main(){
 ll n;
 cin>>n;
 vector<ll> h(n+1);
 vector<ll> a(n+1);
 for(ll i=0;i<n;i++){
 	cin>>h[i];
 }
 for(ll i=0;i<n;i++){
 	cin>>a[i];
 } 
 
 cout<<maxB(h,a);
 
 return 0;
}