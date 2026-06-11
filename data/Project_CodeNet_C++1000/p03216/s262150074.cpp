#include <bits/stdc++.h>
using namespace std;

#define MAXK 75

int N;
string S;
int Q;
int k[MAXK];

int main()
{
	cin >> N;
	cin >> S;
	cin >> Q;
	for( int i = 0; i < Q; i++ ) {
		cin >> k[i];
	}


	for( int j = 0; j < Q; j++ ) {
		long long ans = 0, a = 0, b = 0, ab = 0;
		for( int i = 0; i < N; i++ ) {
			if( S[i] == 'D' ) {
				a++;
			}
			else if( S[i] == 'M' ) {
				ab += a;
				b++;
			}
			else if( S[i] == 'C' ) {
				ans += ab;
			}
			if( i >= k[j] - 1 ) {
				if( S[ i - k[j] + 1 ] == 'D' ) {
					a--;
					ab -= b;
				}
				if( S[ i - k[j] + 1 ] == 'M' ) {
					b--;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
