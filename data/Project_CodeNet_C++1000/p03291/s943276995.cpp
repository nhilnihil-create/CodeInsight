#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz size()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
const ll MOD=1000000007;

//a,b x
int main(){
	string s; cin>>s;
	ll dp[100000][4];//dp[x][y]:x(0-origin)文字まで決めてy個は決めた
	//ans=dp[s.sz-1][3]

	rep(i,100000)rep(j,4) dp[i][j]=0;

	if(s[0]=='A'){
		dp[0][0]=1;
		dp[0][1]=1;
	}
	else if(s[0]=='?'){
		dp[0][0]=3;
		dp[0][1]=1;
	}
	else dp[0][0]=1;

	rep1(i,s.sz-1){
		if(s[i]=='A'){
			rep(j,4) dp[i][j]=dp[i-1][j];
			dp[i][1]+=dp[i-1][0];
			dp[i][1]%=MOD;
		}
		else if(s[i]=='B'){
			rep(j,4) dp[i][j]=dp[i-1][j];
			dp[i][2]+=dp[i-1][1];
			dp[i][2]%=MOD;
		}
		else if(s[i]=='C'){
			rep(j,4) dp[i][j]=dp[i-1][j];
			dp[i][3]+=dp[i-1][2];
			dp[i][3]%=MOD;
		}
		else{
			rep(j,4) dp[i][j]=(dp[i-1][j]*3)%MOD;
			dp[i][1]+=dp[i-1][0];
			dp[i][2]+=dp[i-1][1];
			dp[i][3]+=dp[i-1][2];
			dp[i][1]%=MOD;
			dp[i][2]%=MOD;
			dp[i][3]%=MOD;
		}
	}
	cout<<dp[s.sz-1][3];	
}