#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
vector<ll> invs,invsum;
ll inve(ll x){
	ll pw = mod - 2;
	ll res = 1;
	vector<ll> dbl;
	dbl.pb(x);
	for(int i=1;i<=30;i++){
		dbl.pb( (dbl[i-1]*dbl[i-1])%mod );
	}
	for(int i=0;i<=30;i++){
		if(pw%2==1){
			res *= dbl[i];
			res %= mod;
		}
		pw = pw/2;
	}
	return res;
}
ll fact(ll x){
	ll res=1;
	for(int i=1;i<=x;i++){
		res *= i;
		res %= mod;
	}
	return res;
}
ll calc(ll pos, ll num){
	return (invsum[pos]+invsum[num-pos+1]-1)%mod;
}
int main(){
	ll n;
	cin>>n;
	vector<ll> a;
	ll fn = fact(n);
	invs.pb(0);
	invsum.pb(0);
	for(int i=1;i<=n;i++){
		invs.pb(inve(i));
		invsum.pb( (invsum[i-1]+invs[i])%mod );
	}
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a.pb(x);
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		ll tmp = a[i] * calc(i+1,n);
		ans += tmp;
		ans %= mod;
	}
	ans *= fn;
	ans %= mod;
	cout<<ans<<endl;
	return 0;
}