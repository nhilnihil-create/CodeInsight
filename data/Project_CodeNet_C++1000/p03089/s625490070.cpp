#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
#define sz(a) ll(a.size())
void solve(){
	ll n;
	cin>>n;
	vector<ll> v(n),res;
	for(ll i=0;i<n;i++)
		cin>>v[i];
	while(!v.empty()){
		ll f=0;
		for(ll i=sz(v)-1;i>=0;i--)
			if(v[i]==i+1){
				res.push_back(i+1);
				f=1;
				break;
			}
		if(!f){
			cout<<"-1";
			return;
		}
		vector<ll> temp;
		for(ll i=0;i<sz(v);i++)
			if(i+1!=res.back())
				temp.push_back(v[i]);
		v=temp;
	}
	reverse(res.begin(),res.end());
	for(ll i=0;i<n;i++)
		cout<<res[i]<<"\n";
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