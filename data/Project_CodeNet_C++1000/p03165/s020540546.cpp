#include<bits/stdc++.h>
#define mp make_pair
// #define pb push_back
#define ll long long
#define endl "\n"
using namespace std;



int main() {
	string s1,s2;
	cin>>s1>>s2;
	ll n=s1.length();
	ll m=s2.length();
	ll dp[n+1][m+1];
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=m;j++){
			if(i==0||j==0){
				dp[i][j]=0;
			}
			else if(s1[i-1]==s2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	string ans="";
	ll j=m,i=n;
	while(i>=1&&j>=1){
		if(dp[i][j]==dp[i-1][j]){
			i--;
		}
		else if(dp[i][j]==dp[i][j-1]){
			j--;
		}
		else{
			ans+=s1[i-1];
			j=j-1;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
}







