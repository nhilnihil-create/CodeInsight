#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
#define sz(a) ll(a.size())
ll a[200005],b[200005];
ll f(ll l,ll r,vector<ll> &v){
	auto it=lower_bound(v.begin(),v.end(),l);
	auto ut=lower_bound(v.begin(),v.end(),r);
	return (ut-it);
}
void solve(){
	ll n,res=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++)
		cin>>b[i];
	for(ll bit=0;bit<30;bit++){
		ll val=pow(2,bit+1),cnt=0;
		vector<ll> v;
		for(ll i=1;i<=n;i++)
			v.push_back(b[i]%val);
		sort(v.begin(),v.end());
		val/=2;
		for(ll i=1;i<=n;i++){
			ll x=a[i]%(2*val);
			cnt+=f(val-x,2*val-x,v)+f(3*val-x,4*val-x,v);
		}
		if(cnt&1)
			res+=val;
	}
	cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    clock_t z=clock();
    ll qc=1;
    //cin>>qc;
    for(ll i=1;i<=qc;i++){
        solve();
    }
    debug("Total Time:%.4Lf\n",(ld)(clock()-z)/CLOCKS_PER_SEC);
}