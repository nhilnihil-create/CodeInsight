/// IN THE NAME OF GUITAR
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<ll, ll> pll;

#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
 
ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}
 
const ll MAXN = (1LL << 18) + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7;
pll mx[MAXN];
ll A[MAXN], n, res = 0;

void merge(pll &x, ll y) {
	if (x.S < y) x.S = y;
	if (x.F < x.S) swap(x.F, x.S);
}

int main() {
	scanf("%lld", &n);
	for (ll i = 0; i < 1LL << n; i++) {
		scanf("%lld", &A[i]);
		mx[i].F = A[i];
	}
	
	for (ll j = 0; j < n; j++) {
		for (ll i = 0; i < 1LL << n; i++) {
			if (i & (1LL << j)) {
				merge(mx[i], mx[i ^ (1LL << j)].F);
				merge(mx[i], mx[i ^ (1LL << j)].S);
			}
		}
	}
	
	for (ll i = 1; i < 1LL << n; i++) {
		res = max(res, mx[i].F + mx[i].S);
		printf("%lld\n", res);
	}
    return 0;
}
 