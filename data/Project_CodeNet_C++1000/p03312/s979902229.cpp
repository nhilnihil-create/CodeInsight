#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
vector<ll> sum;
ll fin(ll x, ll y, ll val){
	ll lef = x, rig = y;
	while(rig-lef>1){
		ll mid = (lef+rig)/2;
		if(sum[mid]>val/2)rig=mid;
		else lef = mid;
	}
	ll ldif = abs( sum[lef] - val/2 );
	ll rdif = abs( sum[rig] - val/2 );
	if(ldif<rdif)return lef;
	else return rig;
}
int main(){
	ll n;
	cin>>n;
	vector<ll> a;
	vector<ll> half_normal, half_reversed;
	half_normal.pb(-1);
	half_reversed.pb(-1);
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a.pb(x);
	}
	vector<ll> fixed_sum;
	fixed_sum.pb(a[0]);
	for(int i=1;i<n;i++){
		fixed_sum.pb(fixed_sum[i-1]+a[i]);
	}
	sum.pb(a[0]);
	for(int i=1;i<n;i++){
		sum.pb(sum[i-1]+a[i]);
		half_normal.pb( fin(0,i-1,sum[i]) );
	}
	sum.clear();
	reverse(a.begin(),a.end());
	sum.pb(a[0]);
	for(int i=1;i<n;i++){
		sum.pb(sum[i-1]+a[i]);
		half_reversed.pb( fin(0,i-1,sum[i]) );
	}
	ll ans = -1;
	for(int i=1;i<n-2;i++){
		vector<ll> pqrs;
		ll p = fixed_sum[ half_normal[i] ];
		ll q = fixed_sum[ i ] - fixed_sum[ half_normal[i] ];
		ll r = fixed_sum[ n - 2 - half_reversed[ n-2-i ] ] - fixed_sum[i];
		ll s = fixed_sum[n-1] - fixed_sum[ n - 2 - half_reversed[ n-2-i ] ];
		pqrs.pb(p);
		pqrs.pb(q);
		pqrs.pb(r);
		pqrs.pb(s);
		sort(pqrs.begin(),pqrs.end());
		ll tmp = pqrs[3]-pqrs[0];
		//cout<<p<<" "<<q<<" "<<r<<" "<<s<<" "<<half_normal[i]<<" "<<i<<" "<<n-2-half_reversed[n-2-i]<<endl;;
		if( ans == -1 || tmp<ans){
			ans = tmp;
		}
	}
	cout<<ans<<endl;
	return 0;
}