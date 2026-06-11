#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v( n );
	for( int i = 0; i < n; i++ ) {
		cin >> v[i];
	}

	map<int, int> mp;
	map<int, int> mpe;
	map<int, int> mpo;
	for( int i = 0; i < n; i++ ) {
		mp[ v[i] ]++;
		if( i % 2 ) {
			mpo[ v[i] ]++;
		}
		else {
			mpe[ v[i] ]++;
		}
	}
	if( mp.size() == 1 ) {
		cout << n / 2 << endl;
		return 0;
	}
	int ema = 0;
	for( auto it = mpe.begin(); it != mpe.end(); it++ ) {
		if( it->second > ema ) ema = it->second;
	}
	vector<int> eval;
	for( auto it = mpe.begin(); it != mpe.end(); it++ ) {
		if( it->second == ema ) eval.push_back( it->first );
	}
	int oma = 0;
	for( auto it = mpo.begin(); it != mpo.end(); it++ ) {
		if( it->second > oma ) oma = it->second;
	}
	vector<int> oval;
	for( auto it = mpo.begin(); it != mpo.end(); it++ ) {
		if( it->second == oma ) oval.push_back( it->first );
	}
	if( eval.size() == 1 && oval.size() == 1 && eval[0] == oval[0] ) {
		int ema2 = 0;
		for( auto it = mpe.begin(); it != mpe.end(); it++ ) {
			if( it->first == eval[0] ) continue;
			if( it->second > ema2 ) ema2 = it->second;
		}
		int oma2 = 0;
		for( auto it = mpo.begin(); it != mpo.end(); it++ ) {
			if( it->first == oval[0] ) continue;
			if( it->second > oma2 ) oma2 = it->second;
		}
		if( ema - ema2 < oma - oma2 ) ema = ema2;
		else oma = oma2;
	}
	int nume = n / 2 - ema;
	int numo = n / 2 - oma;
	int ans = nume + numo;

	cout << ans << endl;
}
