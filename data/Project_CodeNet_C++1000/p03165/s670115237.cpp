#include<bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	
	int n, m;
	m = s.length();
	n = t.length();
	
	int dp[m+1][n+1];
	
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			
			if(i==0 || j==0)
			dp[i][j] = 0;
			
			else if(s[i-1] == t[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	int i = m;
	int j = n;
	vector <char> res;
	while(i > 0 && j > 0){
		if(s[i-1] == t[j-1]){
			res.push_back(s[i-1]);
			i--;
			j--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1])
			i--;
			
			else
			j--;
		}
	}
	
	for(int i=res.size()-1;i>=0;i--){
		cout<<res[i];
	}
	return 0;
}