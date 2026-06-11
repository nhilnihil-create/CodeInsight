#include<bits/stdc++.h>
#define mx 1000000007
#define ll long long int

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s,t;
    cin>> s >> t;
    string ans="";
    ll dp[s.size()+1][t.size()+1];
    memset(dp,0,sizeof(dp));
    ll n=s.size(),w=t.size();
    for(ll i=1;i<=n;++i){
    	for(ll j=1;j<=w;++j){
    		if(s[i-1]==t[j-1])
    			dp[i][j]=1+dp[i-1][j-1];
    		else
    			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    	}
    }
    ll i=n,j=w;
    while( i && j){
		if(s[i-1]==t[j-1]){
			ans.append(1,s[i-1]);
			--i;
			--j;
		}else{
			if(dp[i-1][j]>dp[i][j-1])
				--i;
			else
				--j;
		}
    }
    reverse(ans.begin(),ans.end());
    cout<< ans << "\n";
	return 0;
}
