#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

int main( int argc, char *argv[] ) {
	ll a, b, c, d;

	cin >> a >> b >> c >> d;

	cout << min(a,b) + min(c,d) << "\n";
	return 0;
}
