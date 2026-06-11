#include <bits/stdc++.h>
using namespace std;
int n;
int power[1<<16];
long long a[20][20];
long long dp[1<<16],ans[1<<16];
int main(){
	cin>>n;
	for(int i=0;i<16;++i){
		power[1<<i]=i;
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<(1<<n);++i){
		int lb=i&(-i),x=power[lb],pre=i^lb;
		dp[i]=dp[pre];
		for(int j=0;j<n;++j){
			if(pre&(1<<j)){
				dp[i]+=a[j][x];
			}
		}
	}
	for(int i=1;i<(1<<n);++i){
		for(int j=i;j;j=i&(j-1)){
			ans[i]=max(ans[i],ans[i^j]+dp[j]);
		}
	}
	cout<<ans[(1<<n)-1]<<'\n';
	return 0;
}