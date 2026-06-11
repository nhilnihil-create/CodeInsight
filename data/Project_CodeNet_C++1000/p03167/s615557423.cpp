#include<bits/stdc++.h>
#define mp make_pair
// #define pb push_back
#define ll long long
#define endl "\n"
using namespace std;


int main() {
	ll h,w;
	cin>>h>>w;
	string s[h];
	ll dp[h][w];
	for(ll i=0;i<h;i++){
		cin>>s[i];
	}
	dp[0][0]=1LL;
	for(ll i=1;i<w;i++){
		if(dp[0][i-1]==1&&s[0][i]=='.'){
			dp[0][i]=1LL;
		}
		else{
			dp[0][i]=0LL;
		}
	}
	for(ll i=1;i<h;i++){
		if(dp[i-1][0]==1&&s[i][0]=='.'){
			dp[i][0]=1LL;
		}
		else{
			dp[i][0]=0LL;
		}
	}
	for(ll i=1;i<h;i++){
		for(ll j=1;j<w;j++){
			if(s[i][j]=='#'){
				dp[i][j]=0LL;
			}
			else{
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
			}
		}
	}
	cout<<dp[h-1][w-1]<<endl;
}







