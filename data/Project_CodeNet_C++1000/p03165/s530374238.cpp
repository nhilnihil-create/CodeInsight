#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string s, t;
	cin>>s;
	cin>>t;
	ll n=s.size(), m=t.size();
	ll i, j;
	vector<vector<ll>> dp(n+1, vector<ll>(m+1));
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(s[i-1]==t[j-1])
				dp[i][j] = 1+dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	i = n, j = m;
	string ans;
	while(i>0 && j>0){
		if(s[i-1]==t[j-1]){
			ans.push_back(s[i-1]);
			i--;
			j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1])
				i--;
			else
				j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout<<ans<<"\n";
	return 0;
}