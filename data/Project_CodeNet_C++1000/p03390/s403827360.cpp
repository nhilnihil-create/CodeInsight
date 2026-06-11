#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll op(ll n) {
	ll k = n/2;
	if(n%2) {
		return k*(k+1);
	} else {
		return k*k;
	}
}
ll get(ll val) {
	ll s = 0, e = 3e9;
	ll ls = 0;
	while(s <= e) {
		ll m = (s+e)/2;
		if(op(m) >= val) {
			e = m-1;
		} else {
			ls = m;
			s = m+1;
		}
	}
	return ls;
}
int main() {
	ll q;
	scanf("%lld",&q);
	while(q--) {
		ll a,b;
		scanf("%lld %lld",&a,&b);
		ll tot = a*b;
		ll res = get(tot)-2;
		if(a == b) {res = 2*a-2;}
		printf("%lld\n",res);
	}
}