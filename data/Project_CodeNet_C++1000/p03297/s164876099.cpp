// Why am I so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

ll a, b, c, d;

ll roundUp(ll a, ll b) {
	ll ret = 0;

	if (a < 0) {
		ll x = (-a + b - 1) / b;
		a += b * x;
		ret = -x;
	}	

	ret += (a + b - 1) / b;
	return ret;
}

void solve() {                   
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

	if (d < b) {
		printf("No\n");
		return;
	}

	if (a < b) {
		printf("No\n");
		return;
	}

	ll g = __gcd(b, d);
	a %= g;
    
    ll x = g * roundUp(c - b + 1 - a, g);
	printf(x < 0 ? "No\n" : "Yes\n");                 
}

int main() {    
    int tt;
    scanf("%d", &tt);

    while (tt--) {
        solve();
    }

    return 0;
}