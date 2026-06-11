#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 100005, L = 262144;

ll n, a[N], b[N];

struct segtree {
	ll v[2*L];
	void init () {
		for(ll i=2*L;i--;) {
			v[i] = 0;
		}
	}
	void upd (ll P, ll V) {
		P += L;
		while(P) {
			v[P] += V;
			P /= 2;
		}
	}
	ll get (ll S, ll E) {
		S += L;
		E += L;
		ll R = 0;
		while(S <= E) {
			if(S%2 == 1) R += v[S++];
			if(E%2 == 0) R += v[E--];
			S /= 2;
			E /= 2;
		}
		return R;
	}
} seg;

ll cnt () {
	seg.init();
	ll C = 0, R = 0;
	seg.upd(N, 1);
	for(ll i=1;i<=n;i++) {
		C += (b[i] == 1 ? -1 : 1);
		seg.upd(N+C, 1);
	}
	C *= -1;
	for(ll i=n;i>=1;i--) {
		seg.upd(N-C, -1);
		R += seg.get(N-C, 2*N);
		C += (b[i] == 1 ? -1 : 1);
	}
	return R;
}

int main()
{
	scanf("%lld",&n);
	ll S = 0, E = 0;
	for(ll i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		E = max(E, a[i]);
	}
	while(S<E) {
		ll M = (S+E)/2 + 1;
		for(ll i=1;i<=n;i++) {
			b[i] = (a[i] >= M);
		}
		ll C = cnt();
		C < (n*(n+1)/2+1)/2 ? E = M-1 : S = M;
	}
	E = 0;
	for(ll i=1;i<=n;i++) {
		if(a[i] <= S) E = max(E, a[i]);
	}
	printf("%lld\n", E);
}
