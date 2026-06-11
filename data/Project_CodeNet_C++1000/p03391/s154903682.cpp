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
	vector< pair<ll,ll> > dval;
	ll rem=0;
	for(int i=0;i<n;i++){
		ll ta,tb;
		cin>>ta>>tb;
		a.pb(ta);
		b.pb(tb);
	}
	ll ans = 0, f = 0;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i])f=1;
		if(a[i]==b[i]){
			ans += b[i];
		}
		if(a[i]<b[i]){
			ans += a[i];
			rem += b[i]-a[i];
		}
		if(a[i]>b[i]){
			dval.pb( mp(b[i],i) );
			ans += a[i];
		}
	}
	if(f==0){
		cout<<0<<endl;
		return 0;
	}
	sort( dval.begin(),dval.end() );
	ans -= dval[0].first;
	cout<<ans<<endl;
	return 0;
}