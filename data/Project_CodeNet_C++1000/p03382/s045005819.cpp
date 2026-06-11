#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
const int INF = 1<<30;

int n, a[N], ans = 0; 
double mid, _ans = INF;

int main()
{
	scanf( "%d", &n );
	for( int i = 1; i <= n; i ++ )
		scanf( "%d", &a[i] );
	
	sort( a+1, a+1+n );
	double mid = double( a[n] ) / 2;
	for( int i = 1; i <= n; i ++ )
		if( fabs( mid - a[i] ) < _ans ) 
			ans = i, _ans = fabs( mid - a[i] );
	if( ans == n ) ans = n-1;
	
//	for( int i = 1; i <= n; i ++ )
//		printf( "%f\n", fabs( mid - a[i]) );
	
	printf( "%d %d\n", a[n], a[ans] );
		
	return 0;
}