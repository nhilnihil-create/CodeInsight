#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
int main(){
	ll n,k,q;
	cin>>n>>k>>q;
	vector<ll> a;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a.pb(x);
	}
	a.pb(-1);
	ll ans = mod;
	for(int i=0;i<n;i++){
		ll mi = a[i];
		vector<ll> ps;
		vector<ll> cur;
		ps.clear();
		cur.clear();
		for(int j=0;j<=n;j++){
			if(mi<=a[j]){
				cur.pb(a[j]);
				//cout<<j<<a[j]<<endl;
			}
			else{
				if(cur.size()>=k){
					sort(cur.begin(),cur.end());
					for(int ii = 0; ii < cur.size()-k+1 ; ii++){
						ps.pb(cur[ii]);
					}
				}
				cur.clear();
			}
		}
		//cout<<i<<endl;
		sort(ps.begin(),ps.end());
		if( ps.size()>=q){
			ll tmp = ps[q-1]-ps[0];
			if(tmp<ans)ans=tmp;
		}
	}
	cout<<ans<<endl;
	return 0;
}