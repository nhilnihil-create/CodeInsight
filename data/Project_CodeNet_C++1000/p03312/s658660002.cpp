#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 200005, inf = 1e18;

ll n, a[N], s[N], ans = inf;

ll sum (ll S, ll E) {
	return s[E] - s[S-1];
}

ll getb (ll A, ll B) {
	ll S = A, E = B;
	while(S<E) {
		ll M = (S+E)/2;
		sum(A, M) >= sum(M+1, B) ? E = M : S = M+1;
	}
	return S;
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		s[i] = s[i-1] + a[i];
	}
	for(ll i=2;i<=n-2;i++) {
		ll I1[2], I2[2];
		I1[0] = getb(1, i);
		I1[1] = I1[0]+1;
		I2[0] = getb(i+1, n);
		I2[1] = I2[0]+1;
		for(auto &A : I1) {
			for(auto &B : I2) {
				ans = min(ans, max({sum(1, A-1), sum(A, i), sum(i+1, B-1), sum(B, n)}) - min({sum(1, A-1), sum(A, i), sum(i+1, B-1), sum(B, n)}));
			}
		}
	}
	printf("%lld\n",ans);
}
