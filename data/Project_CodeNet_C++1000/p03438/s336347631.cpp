#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
#define sz(a) ll(a.size())
ll a[100005],b[100005];
void solve(){
	ll n,res=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++)
		cin>>b[i];
	for(ll i=1;i<=n;i++)
		if(a[i]>b[i])
			res-=a[i]-b[i];
		else
			res+=(b[i]-a[i])/2;
	if(res>=0)
		cout<<"Yes";
	else
		cout<<"No";
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