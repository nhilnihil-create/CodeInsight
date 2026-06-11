#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

int main( int argc, char *argv[] ) {
	ll n, k, res = 0, tmp;
	cin >> n >> k;

	if ( k == 0 ){
		res = n * n;
	}else{
		for ( ll mod = k + 1 ; mod < n + 1 ; mod++ ){
			res += (mod - k) * ( n / mod );
			tmp = n % mod - k + 1;
			res += tmp > 0 ? tmp : 0;
		}
	}
	cout << res << "\n";
	return 0;
}
