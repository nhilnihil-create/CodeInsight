#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout<<#a<<":"<<a<<endl;
const int INF=0x3f3f3f3f;
const int N=3e3+7;
const int mod=1e9+7;
int maxn,minn;
int T,n,m;
string s;
int dp[N][N];
int sum[N];

int main(){
	int ans=0;
	cin>>n>>s;
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		if(s[i-2]=='<'){
			for(int j=1;j<=i;j++){
				dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%mod;
			}
		}
		else{
			dp[i][i]=0;
			for(int j=i-1;j>=1;j--){
				dp[i][j]=(dp[i-1][j]+dp[i][j+1])%mod;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		ans=(ans+dp[n][i])%mod;
	}
	cout<<ans<<endl;

	return 0;
}



