#include <bits/stdc++.h>
using namespace std;

#define N 50

int n;
int a[N];

int main()
{
	cin >> n;
	for( int i = 0; i < n; i++ ) {
		cin >> a[i];
	}

	int ma = a[0];
	int ma_idx = 0;
	int mi = a[0];
	int mi_idx = 0;
	for( int i = 1; i < n; i++ ) {
		if( a[i] > ma ) {
			ma = a[i];
			ma_idx = i;
		}
		if( a[i] < mi ) {
			mi = a[i];
			mi_idx = i;
		}
	}
	if( ma == mi ) {
		cout << 0 << endl;
	}
	else {
		typedef pair< int, int > P;
		vector<P> v;
		if( abs(ma) > abs(mi) ) {
			for( int i = 1; i < n; i++ ) {
				a[i] += ma * 2;
				v.push_back( make_pair( ma_idx+1, i+1 ) );
				v.push_back( make_pair( ma_idx+1, i+1 ) );
				ma = a[i];
				ma_idx = i;
			}
		}
		else {
			for( int i = n - 2; i >= 0; i-- ) {
				a[i] += mi * 2;
				v.push_back( make_pair( mi_idx+1, i+1 ) );
				v.push_back( make_pair( mi_idx+1, i+1 ) );
				mi = a[i];
				mi_idx = i;
			}
		}

		cout << v.size() << endl;
		for( int i = 0; i < v.size(); i++ ) {
			cout << v[i].first << " " << v[i].second << endl;
		}
	}

	return 0;
}
