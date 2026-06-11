#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int dp[1<<26];
int main(){
	string s;cin>>s;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	int h=0;
	rep(i,s.size()){
		h^=1<<(s[i]-'a');
		int Min=dp[h]+1;
		rep(j,26){
			dp[h]=min(dp[h],dp[h^(1<<j)]+1);
			Min=min(Min,dp[h^(1<<j)]+1);
		}
		if(i==s.size()-1){
			printf("%d\n",Min);
		}
	}
}