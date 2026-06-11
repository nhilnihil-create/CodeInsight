#include<bits/stdc++.h>
#define mp make_pair
// #define pb push_back
#define ll long long
#define endl "\n"
using namespace std;


int main() {
	ll n;
	cin>>n;
	long double a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll req=(n+1)/2;
	long double dp[n+1][req+1];
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=req;j++){
			if(j==0){
				dp[i][j]=1.0;
			}
			else if(i==0){
				dp[i][j]=0.0;
			}
			else{
				dp[i][j]=(a[i-1]*dp[i-1][j-1]) + ((1.0-a[i-1])*dp[i-1][j]);
			}
		}
	}
	cout<<fixed<<setprecision(10)<<dp[n][req]<<endl;
}