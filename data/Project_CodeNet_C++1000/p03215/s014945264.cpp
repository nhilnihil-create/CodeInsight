#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
signed main() {
	int n,m,i,j;
	vector<ll> sum;
	cin>>n>>m;
	ll a[n+1],pf[n+1];
	for(i=1;i<=n;++i) cin>>a[i];
	pf[0] = 0ll;
	for(i=1;i<=n;++i) pf[i] = pf[i-1] + a[i];
	ll maxi = 0ll;
	for(i=1;i<=n;++i) {
		for(j=i;j<=n;++j) {
			sum.push_back(pf[j]-pf[i-1]);
			maxi = max(maxi,pf[j]-pf[i-1]);
		}
	}
	vector<bool> yes(sum.size(),true);
	int max_bit = 0;
	while(maxi) {
		max_bit++;
		maxi/=2;
	}
	ll ans = 0ll;
	vector<int> x;
	for(i=max_bit;i>=0;i--) {
		int cnt = 0;
		for(j=0;j<sum.size();++j) {
			if(yes[j]==true) {
				if((sum[j] & (1ll<<i)) != 0) ++cnt;
				else x.push_back(j);
			}
		}
		if(cnt>=m) {
			ans = ans + (1ll<<i);
			for(j=0;j<x.size();++j)
				yes[x[j]] = false;
		}
		x.clear();
	}
	cout<<ans;
}