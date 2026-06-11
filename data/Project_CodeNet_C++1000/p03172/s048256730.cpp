#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e9+7;

ll ways(vector<ll>&v,ll k){
	vector<vector<ll>> dp(v.size()+1,vector<ll>(k+1,0));
	ll sum=0;
	for(ll i=1;i<=v.size();i++){
		dp[i][0]=1;
		sum+=v[i-1];
		for(ll j=1;j<=k && j<=sum;j++){
			dp[i][j]=(dp[i][j-1]+dp[i-1][j])%M;
			if(j-1-v[i-1]>=0){
				dp[i][j]=(dp[i][j]-dp[i-1][j-1-v[i-1]]+M)%M;
			}
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	return dp[v.size()][k];
}

int main(){
 ll n,k;
 cin>>n>>k;
 vector<ll> v(n);
 for(ll i=0;i<n;i++){
 	cin>>v[i];
 }
 cout<<ways(v,k)<<endl;
 return 0;
}

