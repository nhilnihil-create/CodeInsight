#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int mod=1e9 + 7;
	int n,k;
	cin>>n>>k;

	vector<int> v(n,0);
	for(int i=0;i<n;i++)
		cin>>v[i];

	vector<ll> dp(k+1,0);
	for(int i=0;i<=min(k,v[0]);i++)
		dp[i]=1;

	for(int i=1;i<n;i++){
		vector<ll> pre=dp;
		for(int j=1;j<=k;j++){
			pre[j]+=pre[j-1];
			pre[j]%=mod;
		}

		for(int j=1;j<=k;j++){
			int lo=max(0,j-v[i]),hi=j;
			ll tmp=0;
			if(lo>0)
				tmp=pre[lo-1];
			//cout<<pre[hi]<<endl;
			dp[j]=(pre[hi]-tmp+mod)%mod;
			//cout<<dp[j]<<endl;
		}
	}

	cout<<dp[k]<<endl;

	return 0;
}