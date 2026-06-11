#include"bits/stdc++.h"
#define ll long long
#define inf 1e9+5
using namespace  std;

int main(){

	string s,t;
	cin>>s>>t;

	ll i,j;

	ll dp[s.length()+1][t.length()+1];

	for(i=0;i<=s.length();i++){
		for(j=0;j<=t.length();j++){
			if(i==0||j==0){
				dp[i][j]=0;
			}else{
				if(s[i-1]==t[j-1]){
					dp[i][j] = dp[i-1][j-1]+1;
				}else{
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
	}

	ll l=dp[s.length()][t.length()];
	//cout<<l<<endl;
	string lcs;
	
	i=s.length(),j=t.length();
	while(i>0 && j>0){
		if(s[i-1]==t[j-1]){
			lcs.push_back(s[i-1]);
			i--;
			j--;
		}

		else if(dp[i-1][j]>dp[i][j-1]){
			i--;
		}else{
			j--;
		}
	}
	reverse(lcs.begin(),lcs.end());

	cout<<lcs<<endl;



	return 0;
}