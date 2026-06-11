#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> cnt( 13 );
	cnt[0] = 1;
	int ma = 0;
	for( int i = 0; i < N; i++ ) {
		int D;
		cin >> D;
		cnt[D]++;
		ma = max( ma, cnt[D] );
	}

	if( cnt[0] > 1 || cnt[12] > 1 || ma > 2 ) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> f;
	vector<int> v;
	for( int i = 1; i < 12; i++ ) {
		if( cnt[i] == 1 ) v.push_back( i );
		else if( cnt[i] == 2 ) {
			f.push_back( i );
			f.push_back( 24 - i );
		}
	}
	f.push_back( 0 );
	if( cnt[12] ) f.push_back( 12 );
	int fmi = 24 + 1;
	for( int i = 0; i < f.size(); i++ ) {
		for( int j = i + 1; j < f.size(); j++ ) {
			int d = abs( f[i] - f[j] );
			d = min( d, 24 - d );
			fmi = min( fmi, d );
		}
	}
	int n = v.size();
	int ans = 0;
	for( int mask = 0; mask < 1 << n; mask++ ) {
		int mi = fmi;
		for( int i = 0; i < f.size(); i++ ) {
			for( int j = 0; j < n; j++ ) {
				int d1 = v[j];
				if( mask >> j & 1 ) d1 = 24 - d1;
				int d = abs( f[i] - d1 );
				d = min( d, 24 - d );
				mi = min( mi, d );
			}
		}
		for( int i = 0; i < n; i++ ) {
			int d1 = v[i];
			if( mask >> i & 1 ) d1 = 24 - d1;
			for( int j = i + 1; j < n; j++ ) {
				int d2 = v[j];
				if( mask >> j & 1 ) d2 = 24 - d2;
				int d = abs( d2 - d1 );
				d = min( d, 24 - d );
				mi = min( mi, d );
			}
		}
		ans = max( ans, mi );
	}

	cout << ans << endl;
}
