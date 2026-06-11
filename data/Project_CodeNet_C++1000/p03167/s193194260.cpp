#include"bits/stdc++.h"
#define ll long long
#define inf 100005
#define mod 1000000007
using namespace  std;

vector<vector<ll>>g(inf);
vector<ll>indgree(inf);
vector<ll>dist(inf);
bool visted[inf];



int main(){
	ll h,w;
	cin>>h>>w;

	char arr[h][w];

	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			cin>>arr[i][j];
		}
	}
	
	vector<vector<ll>> dp(h,vector<ll>(w));
	dp[0][0] = 1;

	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			if(j+1<w && arr[i][j+1]=='.'){
				dp[i][j+1]+=dp[i][j];

				if(dp[i][j+1]>=mod){
					dp[i][j+1]-=mod;
				}
			}

			if(i+1<h && arr[i+1][j]=='.'){
				dp[i+1][j]+=dp[i][j];

				if(dp[i+1][j]>=mod){
					dp[i+1][j]-=mod;
				}	
			}
		}
	}

	cout<<dp[h-1][w-1]<<endl;
	return 0;
}