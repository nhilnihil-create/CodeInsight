/*
 *  author: chw0501
 *  reference: http://www.secmem.org/blog/2019/05/15/Education-Dp-Contest-Solution/
 *  created: 25.04.2020 03:55:44(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n;
string s;
//dp[i][j]: 앞의 i개의 숫자를 채워넣을때 1~i 숫자를이용. i번째 숫자는 j. 그런 가짓수
ll dp[3010][3010];
//sum[i][j]: dp[i][1] ~ dp[i][j]까지의 합
ll sum[3010][3010];

int main(){
	cin>>n;
	cin>>s;
	dp[1][1]=1;
	sum[1][1]=1;
	for(int i=2;i<=n;i++){
		if(s[i-2]=='<'){
			for(int j=1;j<=i;j++){
				//dp[i][j]=sum of dp[i-1][1 ~ j-1]
				dp[i][j]=(sum[i-1][j-1]-sum[i-1][0]+MOD)%MOD;
			}
		}else{
			for(int j=1;j<=i;j++){
				//dp[i][j]=sum of dp[i-1][j ~ i-1]
				dp[i][j]=(sum[i-1][i-1]-sum[i-1][j-1]+MOD)%MOD;
			}
		}
		for(int j=1;j<=i;j++){
			sum[i][j]=(sum[i][j-1]+dp[i][j])%MOD;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+dp[n][i])%MOD;
	}
	cout<<ans;
	return 0;
}