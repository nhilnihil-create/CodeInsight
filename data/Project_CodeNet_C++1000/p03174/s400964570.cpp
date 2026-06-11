#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e9+7;

ll dp[21][1<<22];

ll ways(vector<vector<ll>>&v,ll state,ll i){
	if(i==v.size())
		return 1;
		
	if(dp[i][state]==-1){
		ll ans=0;
		for(ll j=0;j<v.size();j++){
			if(v[i][j] && (state>>j)&1){
				state=state^(1<<j);
				ans=(ans+ways(v,state,i+1))%M;
				state=state^(1<<j);			
			}
		}	
		dp[i][state]= ans;
	}
	return dp[i][state];
}

int main(){
 ll n;
 cin>>n;
 vector<vector<ll>> v(n,vector<ll>(n));
 for(ll i=0;i<n;i++){
 	for(ll j=0;j<n;j++){
 		cin>>v[i][j];	
	}
 }
 memset(dp, -1, sizeof(dp));
 ll state=(1<<n)-1;
 cout<<ways(v,state,0)<<endl;
 return 0;
}