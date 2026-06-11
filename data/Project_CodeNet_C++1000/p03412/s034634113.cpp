#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
int main(){
	ll n;
	cin>>n;
	vector<ll> a,b;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a.pb(x);
	}
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		b.pb(x);
	}
	ll ans = 0;
	for(int i=1;i<=29;i++){
		ll md = (1<<i);
		vector<ll> bm;
		for(int j=0;j<n;j++){
			bm.pb(b[j]%md);
		}
		sort(bm.begin(),bm.end());
		//for(int j=0;j<bm.size();j++){cout<<bm[j];}cout<<endl;
		ll cnt = 0;
		for(int j=0;j<n;j++){
			ll ca = a[j]%md;
			ll lef1 = max(md/2 - ca, (ll)0);
			ll rig1 = md/2 * 2 - ca;
			ll lef2 = md/2 * 3 - ca;
			ll rig2 = md/2 * 4 - ca ;
			//cout<<i<<j<<" "<<lef1<<rig1<<" "<<lef2<<rig2<<endl;
			ll c1 = lower_bound(bm.begin(),bm.end(),rig1) - lower_bound(bm.begin(),bm.end(),lef1);
			ll c2 = lower_bound(bm.begin(),bm.end(),rig2) - lower_bound(bm.begin(),bm.end(),lef2);
			cnt += (c1+c2);
		}
		if(cnt%2==1)ans+=(1<<(i-1));
	}
	cout<<ans<<endl;
	return 0;
}