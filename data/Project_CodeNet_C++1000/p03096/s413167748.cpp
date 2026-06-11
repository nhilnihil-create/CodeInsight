#include <bits/stdc++.h>
#define rep(i,n) for((i)=1;(i)<=(n);(i)++)
using namespace std;
const int mod=1e9+7;
int n,i,dp[200005],sum[200005],a[200005];
int main(){
	cin>>n;
	rep(i,n)cin>>a[i];
	dp[0]=1;
	rep(i,n){
		if(a[i]!=a[i-1]) (sum[a[i]]+=dp[i-1])%=mod;
		dp[i]=sum[a[i]];
	}
	cout<<dp[n]<<endl;
	return 0;
}