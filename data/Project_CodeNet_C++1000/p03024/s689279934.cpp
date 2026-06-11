#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
char z[12000];
int cnt;
void work () {
	int i;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	for ( i = 1 ; i <= n ; i++ ) if ( z[i] == 'o' ) cnt++;
	cnt += 15 - n;
	if ( cnt >= 8 ) printf ( "YES\n" );
	else printf ( "NO\n" );
}
int main () {
	work ();
	return 0;
}
