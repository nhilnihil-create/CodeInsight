#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
const int MAXN=3010;
long long sum[MAXN],dp[MAXN][MAXN],res;
char x;
int n;

int main(){
	cin>>n;
	dp[1][1]=1;
	for(int i=2;i<=n;++i){
		cin>>x;
		for(int j=1;j<=n;++j) (sum[j]=sum[j-1]+dp[i-1][j])%=MOD;
		for(int j=1;j<=n;++j){
			if(x=='<') dp[i][j]=sum[j-1]%MOD;
			else dp[i][j]=(sum[i-1]-sum[j-1]+MOD)%MOD;
		}
	}
	for(int i=1;i<=n;(res+=dp[n][i])%=MOD,++i);
	cout<<res<<endl;
	return 0;
}