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

int main( void )
{
	ll n, m, q;
	cin >> n >> m >> q;

	rep( i, m ) {
		ll l, r;
		cin >> l >> r;
		lr[l][r]++;
	}

	reps( i, n ) {
		reps( j, n ) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + lr[i][j];
		}
	}

	ll ans[q] = {};
	rep( i, q ) {
		ll a, b;
		cin >> a >> b;

		ans[i] = sum[b][b] + sum[a - 1][a - 1] - sum[a - 1][b] - sum[b][a - 1];
	}

	rep( i, q ) {
		cout << ans[i] << endl;
	}

	return 0;
}
