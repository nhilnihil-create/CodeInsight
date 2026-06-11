#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> b( N );
	for( int i = 0; i < N; i++ ) {
		cin >> b[i];
	}

	vector<int> a;
	while( b.size() ) {
		int flag = 0;
		for( int i = b.size() - 1; i >= 0; i-- ) {
			if( b[i] == i + 1 ) {
				a.push_back( i + 1 );
				b.erase( b.begin() + i );
				flag = 1;
				break;
			}
		}
		if( flag == 0 ) {
			cout << -1 << endl;
			return 0;
		}
	}
	reverse( a.begin(), a.end() );

	for( int i = 0; i < N; i++ ) {
		cout << a[i] << endl;
	}
}
