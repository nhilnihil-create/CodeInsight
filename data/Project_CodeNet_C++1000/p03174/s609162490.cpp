#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define modulo 1000000007
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
int n;
int a[21][21];
ll dp[1<<21];
ll find(int mask){
	int idx=__builtin_popcount(mask);
	if(idx==n)
		return 1;
	if(dp[mask]!=-1)
		return dp[mask];
	ll ans=0;
	for (int i = 0; i < n; ++i){
		if(a[idx][i] && (!(mask & (1<<i))))
			ans=(ans+find(mask|(1<<i)))%modulo;
	}
	dp[mask]=ans;
	return ans;
}
int main(){
	fast_io;
	cin>>n;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin>>a[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<find(0)<<"\n";
	return 0;
}