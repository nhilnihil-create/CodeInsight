#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
int main(){
	ll n;
	cin>>n;
	vector<ll> a,ans;
	vector< pair<ll,ll> > ma, ne;
	ll c = (1<<n);
	for(int i=0;i<c;i++){
		ll x;
		cin>>x;
		a.pb(x);
	}
	ma.pb(mp(a[0],0));
	ne.pb(mp(-1,-1));
	for(int i=1;i<c;i++){
		vector< pair<ll,ll> > ps;
		ps.pb(mp(a[i],i));
		for(int j=0;j<18;j++){
			if( (i>>j)%2 == 1 ){
				ll cur = i -(1<<j);
				ps.pb( ma[cur] );
				ps.pb( ne[cur] );
			}
		}
		sort( ps.begin(), ps.end() );
		reverse( ps.begin(), ps.end() );
		unique( ps.begin(), ps.end() );
		ma.pb(ps[0]);
		ne.pb(ps[1]);
	}
	ans.pb(0);
	for(int i=1;i<c;i++){
		ll ca = max(ans[i-1], ma[i].first+ne[i].first);
		ans.pb(ca);
	}
	for(int i=1;i<c;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}