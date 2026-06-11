#include <bits/stdc++.h>
using namespace std;

#define MAX 200000

int N;
int A[MAX];

bool check( int x )
{
	typedef pair<int, int> P;
	vector<P> S;

	for( int i = 0; i < N - 1; i++ ) {
		if( A[i + 1] > A[i] ) {
			continue;
		}
		if( x <= 1 ) {
			return false;
		}
		int a = A[i + 1];
		while( S.size() && (*(S.end() - 1)).first > a ) {
			S.pop_back();
		}
		if( S.size() && (*(S.end() - 1)).first == a ) {
			(*(S.end() - 1)).second++;
		}
		else {
			S.push_back( make_pair( a, 1 ) );
		}
		while( (*(S.end() - 1)).second == x ) {
			int d = (*(S.end() - 1)).first;
			if( d == 1 ) {
				return false;
			}
			S.pop_back();
			if( S.size() && (*(S.end() - 1)).first == d - 1 ) {
				(*(S.end() - 1)).second++;
			}
			else {
				S.push_back( make_pair( d - 1, 1 ) );
			}
		}
	}
	return true;
}

int main() {
	cin >> N;
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	int l = 0;
	int r = N;
	while( r - l > 1 ) {
		int m = ( l + r ) / 2;
		if( check( m ) ) {
			r = m;
		}
		else {
			l = m;
		}
	}
	int ans = r;

	cout << ans << endl;

	return 0;
}
