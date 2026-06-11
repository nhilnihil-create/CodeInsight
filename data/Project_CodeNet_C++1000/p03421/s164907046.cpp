#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 300005;

ll n, a, b, ans[N];

int main()
{
	scanf("%lld%lld%lld",&n,&b,&a);
	if(a*b < n || a+b > n+1) {
		puts("-1");
		return 0;
	}
	b -= (n + a - 1) / a;
	for(ll i=(n+a-1)/a;i>=1;i--) {
		ll S = a * (i-1) + 1, E = min(n, S+a-1);
		ll T = min(b, E-S);
		for(ll i=S;i<S+T;i++) {
			ans[i] = i;
		}
		for(ll i=S+T;i<=E;i++) {
			ans[i] = E - (i - (S+T));
		}
		b -= T;
	}
	for(ll i=1;i<=n;i++) {
		printf("%lld ",ans[i]);
	}
}
