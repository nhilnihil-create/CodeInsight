#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
void solve(){
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
	cin>>a[i];
	if(a[n-1]!=2){
		cout<<"-1";
		exit(0);
	}
	ll lo=2,hi=3;
	for(ll i=n-2;i>=0;i--){
		ll x=(lo+a[i]-1)/a[i];
		if(x*a[i]>hi){
			cout<<"-1";
			exit(0);
		}
		ll y=hi/a[i];
		if(y*a[i]<lo){
			cout<<"-1";
			exit(0);
		}
		lo=x*a[i];
		hi=y*a[i]+a[i]-1;
	}
	cout<<lo<<" "<<hi;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll qc=1;
    for(ll i=1;i<=qc;i++)
    solve();
}
