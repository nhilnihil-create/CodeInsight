#include <stdio.h>
#include <algorithm>

using namespace std;

int n , q;
char s[210000];
char t[210000] , d[210000];
int x , y;
int check ( int k ) {
	int i;
	for ( i = 1 ; i <= q ; i++ ) {
		if ( t[i] == s[k] ) {
			if ( d[i] == 'L' ) {
				k--;
			}
			else k++;
			if ( k <= 0 ) return -1;
			if ( k > n ) return 1;
		}
	}
	return 0;
}
void work () {
	int i , l , r , mid;
	scanf ( "%d%d" , &n , &q );
	scanf ( "%s" , s + 1 );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%s%s" , t + i , d + i );
	}
	if ( check ( n ) == -1 ) x = n + 1;
	else {
		l = 0; r = n;
		while ( l < r - 1 ) {
			mid = (l+r)/2;
			if ( check ( mid ) != -1 ) r = mid;
			else l = mid;
		}
		x = r;
	}
	if ( check ( 1 ) == 1 ) l = 0;
	else {
		l = 1; r = n + 1;
		while ( l < r - 1 ) {
			mid = (l+r)/2;
			if ( check ( mid ) != 1 ) l = mid;
			else r = mid;
		}
		y = l;
	}
	//printf ( "%d %d\n" , x , y );
	printf ( "%d\n" , y - x + 1 );
}
int main () {
	work ();
	return 0;
}
