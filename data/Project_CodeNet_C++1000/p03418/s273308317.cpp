#include <iostream>
using namespace std;

long long n , k , sum;

int main ( void )
{
	cin >> n >> k;
	for ( int i = k + 1 ; i <= n ; i++ ) {
		if ( n % i >= k - 1 ) {
			sum += ( n / i ) * ( i - k ) + ( n % i ) - k + 1;
		} else {
			sum += ( n / i ) * ( i - k );
		}
	}
	if ( k == 0 ) {
		sum -= n;
	}
	cout << sum << endl;
	return 0;
}