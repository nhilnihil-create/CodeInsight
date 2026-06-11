#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
#define sz(a) ll(a.size())
ll deg[105];
void solve(){
	ll n;
	cin>>n;
	vector<vector<ll>> v;
	vector<p2> res;
	if(n&1){
		v.push_back(vector<ll>());
		v.back().push_back(n);
		n--;
	}
	for(ll i=1;i<=n/2;i++){
		v.push_back(vector<ll>());
		v.back().push_back(i);
		v.back().push_back(n-i+1);
	}
	for(ll i=0;i<sz(v);i++)
		for(ll j=i+1;j<sz(v);j++)
			if(i!=j)
				for(ll k=0;k<sz(v[i]);k++)
					for(ll t=0;t<sz(v[j]);t++)
						res.push_back({v[i][k],v[j][t]});
	cout<<sz(res)<<"\n";
	for(ll i=0;i<sz(res);i++)
		cout<<res[i].first<<" "<<res[i].second<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    clock_t z=clock();
    ll qc=1;
    //cin>>qc;
    for(ll i=1;i<=qc;i++)
        solve();
    debug("Total Time:%.4Lf\n",(ld)(clock()-z)/CLOCKS_PER_SEC);
}