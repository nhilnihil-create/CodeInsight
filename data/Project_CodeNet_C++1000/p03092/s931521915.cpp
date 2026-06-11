#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<cassert>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
long long dp[5005][5005][2];
int a[5005],id[5005];
int main(){
	int n;
	long long A,B;
	cin>>n>>A>>B;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		id[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j)dp[i][j][0]=min(min(dp[i-1][j][0],dp[i-1][j][1]),dp[i][j-1][0]);
			else dp[i][j][0]=dp[i-1][j][0];
		}
		for(int j=0;j<=n;j++){
			if(j>=id[i])dp[i][j][0]+=A; else dp[i][j][0]+=B;
			dp[i][j][1]=dp[i][j][0];
		}
		long long mi=1e18;
		for(int j=0;j<id[i];j++){
			mi=min(mi,min(dp[i-1][j][0],dp[i-1][j][1]));
		}
		dp[i][id[i]][1]=mi;
	//	cout<<dp[i][id[i]][1]<<" ";
	}
	long long mi=1e18;
	for(int i=0;i<=n;i++){
		mi=min(min(dp[n][i][0],dp[n][i][1]),mi);
	}
	cout<<mi;
}