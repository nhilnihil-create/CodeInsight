#include <bits/stdc++.h>
using namespace std;
const int N=305;
string s;
int k,dp[N][N][N],ANS;
int main() {
	ios::sync_with_stdio(false);
	
	cin>>s;
	cin>>k;
	
	for (int len=0; len<s.size(); len++)
		for (int l=0; l+len<s.size(); l++) 
			for (int x=0; x<=min(k,len); x++) {
				int r=l+len;
				if (l==r) dp[l][r][x]=1;
				if (l<r) dp[l][r][x]=max(dp[l][r][x],dp[l][r-1][x]);
				if (l<r) dp[l][r][x]=max(dp[l][r][x],dp[l+1][r][x]);
				
				if (l+1==r && s[l]!=s[r] && x) dp[l][r][x]=dp[l][r-1][x-1]+1;
						else 
				if (l+1==r && s[l]==s[r] && !x) dp[l][r][x]=2;
				
				if (r && r-l>1 && s[l]!=s[r] && x) dp[l][r][x]=max(dp[l][r][x],dp[l+1][r-1][x-1]+2);
					else
				if (r && r-l>1 && s[l]==s[r]) dp[l][r][x]=max(dp[l][r][x],dp[l+1][r-1][x]+2);
				
				ANS=max(ANS,dp[l][r][x]);	
			}
	
	cout<<ANS<<endl;
} 