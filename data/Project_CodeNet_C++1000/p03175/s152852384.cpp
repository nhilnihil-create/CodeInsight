#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M=1e9+7;
ll dp[100005][2];
vector<vector<ll>> adj;

void prepare(vector<pair<ll,ll>>&e){
	for(auto i:e){
		adj[i.first].push_back(i.second);
		adj[i.second].push_back(i.first);
	}
}

ll ways(ll start,ll parent=-1,ll c=0){

	if(dp[start][c]==-1){
		ll count=1;
		for(ll i:adj[start]){
			if(i!=parent){
				ll cnt=0;
				cnt+=ways(i,start,0);
				cnt%=M;
				if(c==0){
					cnt+=ways(i,start,1)%M;
					cnt%=M;
				}
				count=(count*cnt)%M;
			}
		}
		dp[start][c]=count;
	}
	return dp[start][c];
}


int main(){
 ll n;
 cin>>n;
 vector<pair<ll,ll>> v(n-1);
 for(ll i=0;i<n-1;i++){
 	ll a,b;
 	cin>>a>>b;
 	v[i]={a,b};
 }
 adj.resize(n+1);
 prepare(v);
 memset(dp,-1,sizeof(dp));
 ll ans=(ways(1)+ways(1,-1,1))%M;
 cout<<ans<<endl;
 return 0;
}