#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int N = s.size();
	int l= 0;
	int r = N - 1;
	vector<int> lx;
	vector<int> rx;
	int lxn = 0;
	int rxn = 0;
	while( r > l ) {
		while( s[l] == 'x' ) {
			lx.push_back( l - lxn );
			lxn++;
			l++;
		}
		while( s[r] == 'x' ) {
		rx.push_back( N - 1 - (r + rxn) );
			rxn++;
			r--;
		}
		if( s[l] != s[r] ) {
			cout << -1 << endl;
			return 0;
		}
		l++;
		r--;
	}
	int ans = lx.size() + rx.size();
	map<int, int> mpl;
	for( int i = 0; i < lx.size(); i++ ) {
		mpl[ lx[i] ]++;
	}
	map<int, int> mpr;
	for( int i = 0; i < rx.size(); i++ ) {
		mpr[ rx[i] ]++;
	}
	for( auto it = mpl.begin(); it != mpl.end(); it++ ) {
		int n = it->first;
		int num = min( mpl[n], mpr[n] );
		ans -= num * 2;
	}

	cout << ans << endl;
}
