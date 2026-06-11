#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9+7;
const ll MN = 100100;
ll mul(ll a, ll b) {return (a*b)%M;}
ll bp(ll b, ll p) {
	ll ac = 1;
	while(p) {
		if(p&1) {ac = mul(ac,b);}
		b = mul(b,b);
		p >>= 1;
	}
	return ac;
}
ll inv(ll b) {
	return bp(b,M-2);
}
ll co[MN];
int main() {
	ll n;
	cin >> n;
	memset(co,0,sizeof(co));
	ll val = 0;
	for(int i=0;i<n;i++) {
		val += inv(i+1);
		if(val >= M) {val -= M;}
		co[i] += val;
		co[n-i-1] += val;
	}
	ll fac = 1;
	for(int i=1;i<=n;i++) {
		fac = mul(fac,i);
	}
	for(int i=0;i<n;i++) {
		co[i]--;
		co[i] %= M;
		co[i] = mul(co[i],fac);
	}
	ll tot = 0;
	for(int i=0;i<n;i++) {
		ll t;
		cin >> t;
		tot += mul(co[i],t);
	}
	tot %= M;
	cout << tot << '\n';
}
