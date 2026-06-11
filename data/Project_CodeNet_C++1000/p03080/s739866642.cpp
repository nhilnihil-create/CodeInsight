#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
char z[12000];
int ans;
void work () {
	int i;
	scanf ( "%d" , &n );
	scanf ( "%s" , z + 1 );
	for ( i = 1 ; i <= n ; i++ ) {
		if ( z[i] == 'R' ) ans++;
		else ans--;
	}
	if ( ans > 0 ) printf ( "Yes\n" );
	else printf ( "No\n" );
}
int main () {
	work ();
	return 0;
}
