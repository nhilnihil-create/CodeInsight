#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200006;

struct flower{
	ll hi;
	ll bt;
};

ll n;
vector<flower> v(N);

ll lis(){
   vector<ll> dp(n+1);
   dp[0]=0;
   dp[1]=v[1].bt;
   
   map<ll,ll> m;
   m[v[1].hi]=dp[1];
   ll ans=dp[1];
   for(ll i=2;i<=n;i++){
   	  
   	  dp[i]=v[i].bt;
   	  auto it= m.lower_bound(v[i].hi + 1);
   	  if(it!=m.begin()){
   	  it--;
   	  dp[i]+= it->second;
      }
   	  m[v[i].hi]=dp[i];
   	  it=m.upper_bound(v[i].hi);
   	  while(it!=m.end() && it->second <=dp[i]){
   	        auto temp=it;
			temp++; 
			m.erase(it);
			it=temp;  	
	  }
	 ans=max(ans,dp[i]);
   }	
   return ans;
}

int main(){
    cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>v[i].hi;
	}	
	
	for(ll i=1;i<=n;i++){
		cin>>v[i].bt;
	}	
	
	cout<<lis()<<endl;
}