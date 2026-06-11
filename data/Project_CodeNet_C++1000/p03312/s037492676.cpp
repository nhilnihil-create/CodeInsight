#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define debug(a) cout<<#a<<": ";for(auto i:a)cout<<i<<" ";cout<<'\n';
#define trace(a) cout<<#a<<": "<<a<<"\n"
#define int ll
int a[N];
ll ps[N];
int n;
vector< vector<ll> > poss;
signed main() {
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	int i,j,k,l,m,t;
	cin >> n;
	ll sum = 0;
	for(i = 1;i <= n;i++) {
		cin >> a[i];
		ps[i] = ps[i-1] + a[i];
		sum += a[i];
	}
	ll ans = 1e18;
	for(i = 2;i <= n-2;i++) {
		ll sum1 = ps[i];
		int lid[2],rid[2];
		int id = lower_bound(ps,ps+n,(sum1)/2) - ps;
		lid[0] = id;
		lid[1] = id-1;
		id = lower_bound(ps+i,ps+n,(ps[n] - ps[i])/2 + ps[i]) - ps;
		rid[0] = id;
		rid[1] = id-1;
		for(int j = 0;j < 2;j++) {
			for(int k = 0;k < 2;k++) {
				if(lid[j] < i && lid[j] > 0 && rid[k] > i && rid[k] < n) {
					vector<ll> v = {ps[lid[j]],ps[i] - ps[lid[j]], ps[rid[k]] - ps[i],ps[n] - ps[rid[k]]};
					sort(v.begin(),v.end());
					// trace(i);
					// debug(v);
					ans = min(ans,v[3] - v[0]);
				}
			}
		}
	}
	cout << ans << endl;
}