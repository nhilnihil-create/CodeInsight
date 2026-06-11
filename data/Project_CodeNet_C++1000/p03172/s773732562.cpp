#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N,K,mod=1e9+7;
	cin>>N>>K;
	vector<int>dp1(K+1,1),dp2(K+1);
	while(N--) {
		int a;
		cin>>a;
		for(int i=0;i<=K;i++) dp2[i]=(dp1[i]-(i-a-1>=0?dp1[i-a-1]:0)+mod)%mod;
		dp1[0]=dp2[0];
		for(int i=1;i<=K;i++) dp1[i]=(dp1[i-1]+dp2[i])%mod;
	}
	cout<<dp2[K]<<"\n";
	return 0;
}