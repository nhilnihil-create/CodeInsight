#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e3+10;
int n,s; bitset<N*N> dp;
signed main(){
	dp[0]=1; cin>>n;
	for(int i=1,x;i<=n;i++) cin>>x,dp|=(dp<<x),s+=x;
	for(int i=(s+1)/2;;i++) if(dp[i]) return cout<<i,0;
	return 0;
}
