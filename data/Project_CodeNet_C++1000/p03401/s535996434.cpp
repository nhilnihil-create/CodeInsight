#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

int main( int argc, char *argv[] ) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tmp, n, tot = 0;
	vector<ll> viewpoint(1, 0);
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> tmp;
		tot += abs(viewpoint.back() - tmp);
		viewpoint.push_back(tmp);
	}
	tot += abs(viewpoint.back());
	viewpoint.push_back(0);

	for ( int i = 1 ; i < n + 1 ; i++ ){
		ll without = abs(viewpoint[i-1] - viewpoint[i+1]);
		ll with = abs(viewpoint[i-1] - viewpoint[i]) + abs(viewpoint[i] - viewpoint[i+1]);
		cout << tot - with + without << "\n";
	}


	return 0;
}
