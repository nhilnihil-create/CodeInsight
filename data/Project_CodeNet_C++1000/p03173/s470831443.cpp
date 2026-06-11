#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void prefix(ll arr[],ll n,vector<ll> &sum){
	ll s=0;
	for(ll i=0;i<n;i++){
		s=s+arr[i];
		sum[i]=s;
		//cout<<i<<" "<<sum[i]<<endl;
	}
}
int main(){
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	ll dp[n][n];
	vector<ll> sum(n);
	//dp[i][j] ----minimum cost to combine from i to j
	prefix(arr,n,sum);
	//cout<<sum[0]<<" "<<sum[1]<<" "<<sum[2]<<endl; 
	for(ll i=n-1;i>=0;i--){
		for(ll j=i;j<n;j++){
			if(i==j) dp[i][j]=0;
			else{
				dp[i][j]=1e18+5;
				for(ll k=i;k<j;k++){
					if(i-1>=0)
						dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
					else
						dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]);
				}
			}
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<dp[0][n-1]<<endl;
}