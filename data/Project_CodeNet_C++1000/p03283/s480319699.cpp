#include <bits/stdc++.h>

#define rep(i, n) for ( ll i = 0; i < (n); ++i )
#define reps(i, n) for ( ll i = 1; i <= (n); ++i )
#define _rep(i, n) for ( ll i = (n) - 1; i >= 0; --i )
#define _reps(i, n) for ( ll i = n; i > 0; --i )
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll =  long long;
using P = pair<ll, ll>;

ll lr[501][501];
ll sum[501][501];

ll dp( ll l, ll r ){
	if ( sum[l][r] == -1 ) {
		sum[l][r] = dp(l, r - 1) + dp(l - 1, r) - dp(l - 1, r - 1) + lr[l][r];
	}

	return sum[l][r];
}

int main( void )
{
	ll n, m, q;
	cin >> n >> m >> q;

	rep( i, m ) {
		ll l, r;
		cin >> l >> r;
		lr[l][r]++;
	}

	fill((ll *)sum, (ll *)(sum + 501), -1);

	rep( i, q ) {
		ll a, b;
		cin >> a >> b;

		cout << (dp(b, b) + dp(a - 1, a - 1) - dp(a - 1, b) - dp(b, a- 1)) << endl;
	}

	return 0;
}
