#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<iterator>
#include<stack>
#include<queue>
#include<utility>
#include<functional>
#include<bitset>
#include<numeric>
#include<cstring>
#include<tuple>
using namespace std;

long long n, a, b, ans = 0;

bool solve( long long m )
{
	return ( m >= 1 && ( n == ( m + 1 ) * ( n / m ) ) );
}

int main( void )
{
	ios :: sync_with_stdio( 0 );
	cin.tie( 0 );
	
	cin >> n;
	for( long long i = 1; i * i <= n; ++i )
	{
		if( n % i == 0 )
		{
			a = i; b = n / i;
			if( solve( a - 1 ) )
			{
				ans += a - 1;
			}
			if( a != b && solve( b - 1 ) )
			{
				ans += b - 1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}