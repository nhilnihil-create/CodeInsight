#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, a, lt=1, md, rt=3, ans=1e18, s[200005];
ll f(ll p, ll q, ll r, ll s) {
	ll mx = max(max(p,q), max(r,s));
	ll mn = min(min(p,q), min(r,s));
	return mx-mn;
}

int main() {
	cin>>n;
	for (ll i=1; i<=n; i++) scanf("%lld", &a), s[i] = s[i-1] + a;
	for (md=2; md<=n-2; md++) {
		while (abs(s[md] - 2*s[lt+1]) < abs(s[md] - 2*s[lt])) lt++;
		while (abs(s[n] - 2*s[rt+1] + s[md]) < abs(s[n] - 2*s[rt] + s[md])) rt++;
		ans = min(ans, f(s[lt], s[md]-s[lt], s[rt]-s[md], s[n]-s[rt]));
	}
	cout<<ans;
	return 0;
}